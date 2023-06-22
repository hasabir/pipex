/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasabir <hasabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 20:19:11 by hasabir           #+#    #+#             */
/*   Updated: 2022/07/06 14:42:13 by hasabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_child_cmd(int fd[2], char **av, char **envp)
{
	int		input;
	char	**arg;
	char	*pathname;

	if (close (fd[0]) == -1)
		ft_error(0, 0);
	input = open(av[1], O_RDONLY);
	if (input == -1)
		ft_error(0, 0);
	if (dup2(input, STDIN_FILENO) == -1)
		ft_error(0, 0);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		ft_error(0, 0);
	if (close(fd[1]) == -1)
		ft_error(0, 0);
	arg = ft_split(av[2], ' ');
	pathname = check_command(arg[0], envp);
	if (ft_strnstr(arg[0], "grep", ft_strlen(arg[0])) == 1
		&& arg[1] != 0 && check_args(arg[1]) == 1)
		arg[1] = split_arg(arg[1]);
	if (execve(pathname, arg, envp) == -1)
		ft_error(2, arg[0]);
	return ;
}

void	exec_main_cmd(int fd[2], char **av, char **envp)
{
	int		output;
	char	**arg;
	char	*pathname;

	if (close(fd[1]) == -1)
		ft_error(0, 0);
	output = open(av[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (output == -1)
		ft_error(0, 0);
	if (dup2(output, STDOUT_FILENO) == -1 || dup2(fd[0], STDIN_FILENO) == -1)
		ft_error(0, 0);
	if (close(fd[0]) == -1 || close(output) == -1)
		ft_error(0, 0);
	arg = ft_split(av[3], ' ');
	pathname = check_command(arg[0], envp);
	if (ft_strnstr(arg[0], "grep", ft_strlen(arg[0])) == 1
		&& arg[1] != 0 && check_args(arg[1]) == 1)
		arg[1] = split_arg(arg[1]);
	if (execve(pathname, arg, envp) == -1)
		ft_error(2, arg[0]);
	return ;
}

int	main(int ac, char **av, char **envp)
{	
	int	fd[2];
	int	id;
	int	id2;

	if (ac != 5)
		exit (EXIT_FAILURE);
	if (pipe(fd) == -1)
		ft_error(0, 0);
	id = fork();
	if (id == -1)
		ft_error(0, 0);
	if (id == 0)
		exec_child_cmd(fd, av, envp);
	id2 = fork();
	if (id2 == -1)
		ft_error(0, 0);
	if (id2 == 0)
		exec_main_cmd(fd, av, envp);
	if (close(fd[1]) == -1 || close(fd[0]) == -1)
		ft_error(0, 0);
	if (waitpid(id, NULL, 0) == -1 || waitpid(id2, NULL, 0) == -1)
		ft_error(0, 0);
	return (0);
}
