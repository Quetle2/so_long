/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandrad <miandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:57:40 by miandrad          #+#    #+#             */
/*   Updated: 2022/10/27 14:03:47 by miandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*destnew;
	unsigned char	*srcnew;

	srcnew = (unsigned char *)src;
	destnew = (unsigned char *)dest;
	i = 0;
	if (!src && !dest)
		return (0);
	while (i < n)
	{
		destnew[i] = srcnew[i];
		i++;
	}
	return (dest);
}
