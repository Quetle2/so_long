/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandrad <miandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 10:34:17 by miandrad          #+#    #+#             */
/*   Updated: 2022/11/07 14:55:52 by miandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t	i;
	char	*p;

	p = (void *)str;
	i = 0;
	while (i < n)
	{
		if (*p == (char)c)
		{
			return ((void *)p);
		}
		p++;
		i++;
	}
	return (0);
}
