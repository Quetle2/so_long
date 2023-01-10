/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandrad <miandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:30:33 by miandrad          #+#    #+#             */
/*   Updated: 2022/10/27 15:38:24 by miandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t noob, size_t size)
{
	unsigned char	*poi;

	poi = malloc(noob * size);
	if (!poi)
		return (0);
	ft_bzero(poi, noob * size);
	return ((void *)poi);
}
