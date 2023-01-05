/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandrad <miandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:11:16 by miandrad          #+#    #+#             */
/*   Updated: 2023/01/05 17:55:25 by miandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../So_long.h"

int	wall_check(char **map, t_ptr *inf)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen_gnl(map[0], 1) - 1;
	while (i <= j)
	{
		if (map[0][i] != '1' || map[inf->m_hgt - 1][i] != '1')
			return (0);
		i++;
	}
	i = 1;
	while (map[i])
	{
		if ((ft_strlen_gnl(map[i], 1) - 1) != j)
			return (0);
		if (map[i][0] != '1' || map[i][j] != '1')
			return (0);
		i++;
	}
	return (1);
}