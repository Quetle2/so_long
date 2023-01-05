/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandrad <miandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:43:50 by miandrad          #+#    #+#             */
/*   Updated: 2023/01/04 18:24:42 by miandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_temhador(char *src)
{
	char	*dest;
	int		i;
	int		e;

	e = ft_strlen_gnl(src, 1);
	i = 0;
	if (!src[e])
	{
		free(src);
		return (0);
	}
	dest = ft_calloc(ft_strlen_gnl(src, 0) - e + 1, sizeof(char));
	e++;
	while (src[e])
		dest[i++] = src[e++];
	free(src);
	return (dest);
}

char	*ft_linhador(char *src)
{
	char	*dest;

	if (!src[0])
		return (0);
	dest = ft_substr(src, 0, ft_strlen_gnl(src, 1) + 1);
	return (dest);
}

char	*ft_free(char *res, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(res, buffer);
	free(res);
	return (temp);
}

char	*ft_ler(char *temp, int fd)
{
	char		*buff;
	int			read_ret;

	buff = malloc(BUFFER_SIZE + 1);
	read_ret = 1;
	while (!ft_strchr(temp, '\n') && read_ret != 0)
	{
		read_ret = (int)read(fd, buff, BUFFER_SIZE);
		if (read_ret == -1)
		{
			free(buff);
			free(temp);
			return (0);
		}
		buff[read_ret] = '\0';
		temp = ft_free(temp, buff);
	}
	free(buff);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*linha;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
	{
		free(temp);
		temp = NULL;
		return (0);
	}
	if (!temp)
	{
		temp = malloc(1);
		temp[0] = '\0';
	}
	temp = ft_ler(temp, fd);
	if (!temp)
		return (0);
	linha = ft_linhador(temp);
	temp = ft_temhador(temp);
	return (linha);
}
