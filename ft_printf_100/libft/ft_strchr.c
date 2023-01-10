/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandrad <miandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 09:56:08 by miandrad          #+#    #+#             */
/*   Updated: 2022/11/10 17:02:11 by miandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	if ((char)c == '\0')
		return ((char *)str + ft_strlen(str));
	while (str)
	{
		if (*str == (char)c)
		{
			return ((char *)str);
		}
		else if (*str == 0)
			return (0);
		str++;
	}
	return (0);
}
