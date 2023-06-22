/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasabir <hasabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 17:17:33 by hasabir           #+#    #+#             */
/*   Updated: 2022/07/06 14:42:11 by hasabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_bzero(void	*s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	p = malloc(count * size);
	if (!p)
		return (0);
	ft_bzero (p, count * size);
	return (p);
}

char	*ft_strtrim(char *s1, char *set)
{
	int	i;
	int	st;
	int	en;

	i = 0;
	if (!s1 && !set)
		return (NULL);
	if (!s1)
		return ((char *)ft_calloc(1, sizeof (char)));
	while (s1[i] && ft_strchr(set, s1[i]) != 0)
		i++;
	if (i == ft_strlen(s1))
		return (ft_calloc(1, sizeof(char)));
	if (s1[i] == 0)
		return (0);
	st = i;
	i = ft_strlen((char *)s1) - 1;
	while (i > 0 && ft_strchr(set, s1[i]) != 0)
		i--;
	en = i;
	return (ft_substr(s1, st, en - st + 1));
}

char	*ft_strchr(char *s, int c)
{
	unsigned char	*ss;

	ss = (unsigned char *)s;
	while (*ss)
	{
		if (*ss == (unsigned char)c)
		{
			return ((char *)ss);
		}
		ss++;
	}
	if (c == 0)
		return ((char *)ss);
	return (0);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*p;
	int		i;

	if (!s)
		return (NULL);
	if (len > ft_strlen(s))
		len = ft_strlen(s) - start;
	if (start > ft_strlen(s))
		return ((char *)ft_calloc(1, sizeof(char)));
	p = (char *)ft_calloc((len + 1), sizeof(char));
	if (!p)
		return (NULL);
	i = 0;
	while (i < len)
	{
		p[i] = s[start];
		start++;
		i++;
	}
	return (p);
}
