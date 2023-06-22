/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasabir <hasabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 17:30:52 by hasabir           #+#    #+#             */
/*   Updated: 2022/07/06 14:42:10 by hasabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*search_path(char **env, char *to_find, char *arg)
{
	int		j;
	char	*path;
	int		i;

	i = 0;
	path = 0;
	while (env[i])
	{
		j = 0;
		while (j < 6)
		{
			if (env[i][j] != to_find[j])
				break ;
			j++;
		}
		if (j == 5)
		{
			path = env[i];
			return (path + j);
		}
		i++;
	}
	if (path == NULL)
		ft_error(1, arg);
	return (0);
}

int	ft_strnstr(const char *s1, const char *s2, int len)
{
	int	i;
	int	j;

	i = 0;
	if (!s1 && s2[i] == 0)
		return (-1);
	if (s1[i] == 0 && s2[i] == 0)
		return (-1);
	if (!*s2)
		return (-1);
	while (s1[i] && i < len)
	{
		j = 0;
		while (s1[i + j] && s2[j] && s2[j] == s1[i + j]
			&& i + j < len)
			j++;
		if (s2[j] == 0)
			return (1);
		i++;
	}
	return (-1);
}

char	*split_arg(char *arg)
{
	char	**stock;

	stock = ft_split(arg, '\'');
	free(arg);
	arg = stock[0];
	free(stock);
	return (arg);
}
