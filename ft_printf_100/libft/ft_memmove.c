/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandrad <miandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:42:24 by miandrad          #+#    #+#             */
/*   Updated: 2022/11/03 12:44:01 by miandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	unsigned char	*destnew;
	unsigned char	*srcnew;

	srcnew = (unsigned char *)str2;
	destnew = (unsigned char *)str1;
	if (!srcnew && !destnew)
		return (0);
	if (srcnew < destnew)
	{
		while (n > 0)
		{
		destnew[n - 1] = srcnew[n - 1];
		n--;
		}
	}
	else
	{
		while (n > 0)
		{
			*destnew++ = *srcnew++;
			n--;
		}
	}
	return (str1);
}
