/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandrad <miandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:54:43 by miandrad          #+#    #+#             */
/*   Updated: 2023/01/11 15:02:06 by miandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(const char *str, int n)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	if (n == 1)
	{
		while (str[i] != '\n' && str[i])
			i++;
		return (i);
	}
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *str1, char const *str2)
{
	size_t	i;
	char	*p;

	i = 0;
	if (!str1 || !str2)
		return (0);
	p = malloc(ft_strlen_gnl(str1, 0) + ft_strlen_gnl(str2, 0) + 1);
	if (!p)
		return (0);
	while (*str1 != '\0')
		p[i++] = *str1++;
	while (*str2 != '\0')
		p[i++] = *str2++;
	p[i] = '\0';
	return (p);
}

char	*ft_strchr(const char *str, int c)
{
	if (c == '\0')
		return ((char *)str + ft_strlen_gnl(str, 0));
	while (str)
	{
		if (*str == c)
		{
			return ((char *)str);
		}
		else if (*str == 0)
			return (0);
		str++;
	}
	return (0);
}

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	size_t	i;
	char	*p;

	i = 0;
	if (!str)
		return (0);
	if (len == 0 || start >= ft_strlen_gnl(str, 0))
	{
		p = malloc(1);
		p[i] = '\0';
		return (p);
	}
	if (len <= ft_strlen_gnl(str, 0) - start)
		p = ft_calloc(len + 1, sizeof(char));
	else
		p = ft_calloc(ft_strlen_gnl(str, 0) - start + 1, sizeof(char));
	if (!p)
		return (0);
	while (str[start] && i < len && start < ft_strlen_gnl(str, 0))
		p[i++] = str[start++];
	p[i] = '\0';
	return (p);
}

void	*ft_calloc(size_t noob, size_t size)
{
	unsigned char	*poi;
	size_t			i;

	poi = malloc(noob * size);
	i = 0;
	if (!poi)
		return (0);
	while (i < (noob * size))
	{
		poi[i] = '\0';
		i++;
	}
	return ((void *)poi);
}
