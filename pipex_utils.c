/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasabir <hasabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 18:28:52 by hasabir           #+#    #+#             */
/*   Updated: 2022/07/04 20:16:46 by hasabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strlen(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_strcpy(char *dst, char *src, int dstsize)
{
	int	i;

	i = 0;
	while (src[i] && i < (dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return ;
}

char	*ft_strdup(char	*s)
{
	char	*p;
	int		len;

	len = ft_strlen(s) + 1;
	p = (char *)malloc(len);
	if (!p)
		exit (EXIT_FAILURE);
	ft_strcpy(p, s, len);
	return (p);
}

char	*ft_strjoin(char *path, char *args)
{
	char	*p;
	int		len1;
	int		len2;
	int		i;
	int		j;

	len1 = ft_strlen((char *)path);
	len2 = ft_strlen((char *)args);
	p = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!p)
		exit (EXIT_FAILURE);
	i = -1;
	while (++i < len1)
		p[i] = path[i];
	j = -1;
	while (++j < len2)
		p[i++] = args[j];
	p[i] = '\0';
	return (p);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}
