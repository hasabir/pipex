/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasabir <hasabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 08:56:29 by hasabir           #+#    #+#             */
/*   Updated: 2022/07/06 14:41:56 by hasabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_lenmat(char *s, char c)
{
	int		i;
	int		len;

	len = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			len++;
		while (s[i] != c && s[i])
			i++;
	}
	return (len);
}

int	ft_lenword(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	*ft_alloc(char *s, char c, char **p, int k)
{
	int	i;
	int	j;

	i = ft_lenword(s, c);
	p[k] = ft_calloc(i + 1, sizeof (char));
	if (!p)
	{
		j = 0;
		while (j++ < k)
			free(p[j]);
		free(p);
		return (0);
	}
	return (p[k]);
}

char	**fill(char *s, char c, char **p, int h)
{
	int	i;
	int	a;
	int	j;

	i = -1;
	while (s[h] && ++i < ft_lenmat(s, c))
	{
		while (s[h] == c)
			h++;
		if (s[h] != c)
		{
			ft_alloc(s + h, c, p, i);
			if (!p)
				return (0);
		}	
		a = ft_lenword(s + h, c);
		j = -1;
		h -= 1;
		while (s[++h] != c && ++j < a)
			p[i][j] = s[h];
	}
	return (p);
}

char	**ft_split(char *s, char c)
{
	char	**p;

	if (!s)
		return (0);
	p = ft_calloc(ft_lenmat(s, c) + 1, sizeof (char *));
	if (!p)
		return (0);
	return (fill(s, c, p, 0));
}
