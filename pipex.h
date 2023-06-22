/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasabir <hasabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:41:38 by hasabir           #+#    #+#             */
/*   Updated: 2022/07/06 14:43:28 by hasabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <strings.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>

char	**ft_split(char *s, char c);
int		ft_lenmat(char *s, char c);
char	*ft_strjoin(char *path, char *args);
char	*search_path(char **env, char *to_find, char *arg);
int		ft_strcmp(char *s1, char *s2);
char	*check_command(char *arg, char **env);
int		check_args(char *arg);
void	ft_error(int error_num, char *cmd_name);
int		ft_strlen(char	*str);
char	*ft_strtrim(char *s1, char *set);
char	*ft_strchr(char *s, int c);
char	*ft_substr(char *s, int start, int len);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void	*s, size_t n);
int		ft_strnstr(const char *s1, const char *s2, int len);
char	*split_arg(char *arg);

#endif