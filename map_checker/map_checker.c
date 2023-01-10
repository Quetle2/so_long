/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandrad <miandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:11:16 by miandrad          #+#    #+#             */
/*   Updated: 2023/01/10 18:34:42 by miandrad         ###   ########.fr       */
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
	int	j;
	int	p;
	int	e;

	inf->index = 0;
	p = 0;
	e = 0;
	while (map[inf->index])
	{
		j = 0;
		while (map[inf->index][j])
		{
			if (map[inf->index][j] != 'C' && map[inf->index][j] != 'P'
				&& map[inf->index][j] != 'E' && map[inf->index][j] != '0'
				&& map[inf->index][j] != '1' && map[inf->index][j] != '\n')
				return (0);
			if (map[inf->index][j] == 'C')
				inf->map.food++;
			if (map[inf->index][j] == 'P')
			{
				p++;
				inf->plr.x = j;
				inf->plr.y = inf->index;
			}
			if (map[inf->index][j] == 'E')
			{
				e++;
				inf->map.end_x = j - 1;
				inf->map.end_y = inf->index;
			}
			j++;
		}
		inf->index++;
	}
	if (inf->map.food != 0 && p == 1 && e == 1)
	{
		if (check_path(inf->plr.y, inf->plr.x, inf, map))
			return (1);
	}
	return (0);
}

int	check_path(int i, int j, t_info *inf, char **map)
{
	printf("curr x: %d\ncurr y: %d\n", inf->map.end_x, inf->map.end_y, j, i);
	// if (j == inf->map.end_x && i == inf->map.end_y)
	// {
	// 	return (1);
	// }
	if (map[i][j] == '0' ||  map[i][j] == 'P' || map[i][j] == 'C')
	{
		map[i][j] = '-';
		if (check_path(i, j - 1, inf, map))
			return (1);
		if (check_path(i + 1, j, inf, map))
			return (1);
		if (check_path(i, j + 1, inf, map))
			return (1);
		if (check_path(i - 1, j, inf, map))
			return (1);
	}
	return (0);
}
