/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandrad <miandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:11:16 by miandrad          #+#    #+#             */
/*   Updated: 2023/01/18 15:51:44 by miandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../So_long.h"

int	wall_check(t_info *inf)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen_gnl(inf->matrix[0], 1) - 1;
	while (i <= j)
	{
		if (inf->matrix[0][i] != '1'
		|| inf->matrix[inf->map.height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 1;
	while (i < inf->map.height)
	{
		if ((int)(ft_strlen_gnl(inf->matrix[i], 1) - 1) != j)
			return (0);
		if (inf->matrix[i][0] != '1' || inf->matrix[i][j] != '1')
			return (0);
		i++;
	}
	return (check_cpe(inf));
}

int	check_cpe(t_info *inf)
{
	int	j;
	int	p;
	int	e;

	inf->i = 0;
	p = 0;
	e = 0;
	while (inf->matrix[inf->i])
	{
		j = 0;
		while (inf->matrix[inf->i][j])
		{
			if (inf->matrix[inf->i][j] != 'C' && inf->matrix[inf->i][j] != 'P'
				&& inf->matrix[inf->i][j] != 'E'
				&& inf->matrix[inf->i][j] != '0'
				&& inf->matrix[inf->i][j] != '1'
				&& inf->matrix[inf->i][j] != '\n'
				&& inf->matrix[inf->i][j] != 'I')
				return (0);
			if (inf->matrix[inf->i][j] == 'C')
				inf->map.food++;
			if (inf->matrix[inf->i][j] == 'P')
			{
				p++;
				inf->plr.x = j;
				inf->plr.y = inf->i;
			}
			if (inf->matrix[inf->i][j] == 'E')
			{
				e++;
				inf->map.end_x = j;
				inf->map.end_y = inf->i;
			}
			j++;
		}
		inf->i++;
	}
	if (inf->map.food != 0 && p == 1 && e == 1)
		if (check_path(inf->plr.y, inf->plr.x, inf))
			return (1);
	return (0);
}

int	check_path(int i, int j, t_info *inf)
{
	if (inf->matrix[i][j] == '0' || inf->matrix[i][j] == 'P'
	|| inf->matrix[i][j] == 'C' || inf->matrix[i][j] == 'E')
	{
		if (inf->matrix[i][j] == '0')
			inf->matrix[i][j] = '-';
		if (inf->matrix[i][j] == 'C')
			inf->matrix[i][j] = 'c';
		if (inf->matrix[i][j] == 'E')
			inf->matrix[i][j] = 'e';
		if (inf->matrix[i][j] == 'P')
			inf->matrix[i][j] = 'p';
		if (check_path(i - 1, j, inf))
			return (1);
		if (check_path(i, j + 1, inf))
			return (1);
		if (check_path(i + 1, j, inf))
			return (1);
		if (check_path(i, j - 1, inf))
			return (1);
	}
	return (0);
}
