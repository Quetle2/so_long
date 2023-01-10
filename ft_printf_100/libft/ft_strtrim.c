/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandrad <miandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:00:54 by miandrad          #+#    #+#             */
/*   Updated: 2022/10/28 15:35:05 by miandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *str1, char const *set)
{
	size_t	start;
	size_t	cont;

	start = 0;
	if (!str1)
		return (0);
	while (str1[start] && ft_strchr(set, str1[start]))
		start++;
	cont = ft_strlen(str1);
	while (ft_strchr(set, str1[cont - 1]) && cont > 0)
	{
		cont--;
	}
	if (cont == 0)
		cont = start;
	return (ft_substr(str1, start, cont - start));
}
