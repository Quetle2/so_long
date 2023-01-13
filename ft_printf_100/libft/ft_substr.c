/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandrad <miandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:36:56 by miandrad          #+#    #+#             */
/*   Updated: 2023/01/13 16:25:22 by miandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	size_t	i;
	char	*p;

	i = 0;
	if (!str)
		return (0);
	if (len == 0 || start >= ft_strlen(str))
	{
		p = malloc(1);
		p[i] = '\0';
		return (p);
	}
	if (len <= ft_strlen(str) - start)
		p = malloc(len + 1);
	else
		p = malloc(ft_strlen(str) - start + 1);
	if (!p)
		return (NULL);
	while (str[start] && i < len && start < ft_strlen(str))
		p[i++] = str[start++];
	p[i] = '\0';
	return (p);
}
