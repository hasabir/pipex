/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasabir <hasabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 11:32:17 by hasabir           #+#    #+#             */
/*   Updated: 2022/07/06 14:43:18 by hasabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(int error_num, char *cmd_name)
{
	if (error_num == 1)
	{
		write(2, "command not found: ", 19);
		cmd_name = ft_strtrim(cmd_name, "/");
		write(2, cmd_name, ft_strlen(cmd_name));
		write (2, "\n", 1);
		exit(EXIT_FAILURE);
	}
	else if (error_num == 2)
	{
		write(2, strerror(2), ft_strlen(strerror(2)));
		write(2, ": ", 2);
		write(2, cmd_name, ft_strlen(cmd_name));
		write(2, "\n", 1);
		exit(EXIT_FAILURE);
	}
	perror(NULL);
	exit(EXIT_FAILURE);
}

int	check_args(char *arg)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (arg[i] == '\'' && arg[i])
	{	
		i++;
		j++;
	}
	while (arg[i] != '\'' && arg[i])
		i++;
	while (arg[i] == '\'' && arg[i])
	{
		i++;
		j--;
	}
	if (j % 2 != 0)
		exit(EXIT_FAILURE);
	return (1);
}

void	ft_free(char **matrix, char *arg)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
	if (arg)
		free(arg);
	return ;
}

char	*check_command(char *arg, char **env)
{
	char	*stock;
	char	**matrix;
	char	*pathname;
	int		a;
	int		i;

	if (arg[0] == '/' || arg[0] == '.')
		return (arg);
	stock = search_path(env, "PATH=", arg);
	matrix = ft_split(stock, ':');
	arg = ft_strjoin("/", arg);
	a = 0;
	i = -1;
	while (matrix[++i])
	{
		pathname = ft_strjoin(matrix[i], arg);
		a = access(pathname, F_OK);
		if (a == 0)
			break ;
		free(pathname);
	}	
	if (a == -1 && !*matrix)
		ft_error(1, arg);
	ft_free(matrix, arg);
	return (pathname);
}
