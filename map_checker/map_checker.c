/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandrad <miandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:11:16 by miandrad          #+#    #+#             */
/*   Updated: 2023/01/06 18:17:12 by miandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../So_long.h"

int	wall_check(char **map, t_info *inf)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen_gnl(map[0], 1) - 1;
	while (i <= j)
	{
		if (map[0][i] != '1' || map[inf->map.height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 1;
	while (i < inf->map.height)
	{
		if ((ft_strlen_gnl(map[i], 1) - 1) != j)
			return (0);
		if (map[i][0] != '1' || map[i][j] != '1')
			return (0);
		i++;
	}
	return (check_cpe(map, inf));
}

int	check_cpe(char **map, t_info *inf)
{
	int	i;
	int	j;
	int	p;
	int	e;

	i = 0;
	p = 0;
	e = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != 'C' && map[i][j] != 'P' && map[i][j] != 'E'
				&& map[i][j] != '0' && map[i][j] != '1' && map[i][j] != '\n')
				return (0);
			if (map[i][j] == 'C')
				inf->map.food++;
			if (map[i][j] == 'P')
				p++;
			if (map[i][j] == 'E')
				e++;
			j++;
		}
		i++;
	}
	if (inf->map.food != 0 && p == 1 && e == 1)
	{
		printf("Yass\n");
		return (1);
	}
	return (0);
}
