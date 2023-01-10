/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandrad <miandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:33:16 by miandrad          #+#    #+#             */
/*   Updated: 2022/10/27 16:59:46 by miandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *str1, char const *str2)
{
	size_t	i;
	char	*p;

	i = 0;
	if (!str1 || !str2)
		return (0);
	p = malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	if (!p)
		return (0);
	while (*str1 != '\0')
	{
		p[i] = *str1;
		i++;
		str1++;
	}
	while (*str2 != '\0')
	{
		p[i] = *str2;
		i++;
		str2++;
	}
	p[i] = '\0';
	return (p);
}
