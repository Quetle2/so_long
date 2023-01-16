/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandrad <miandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:34:07 by miandrad          #+#    #+#             */
/*   Updated: 2023/01/16 11:57:19 by miandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_long.h"

void	sprite_atribution(t_info *inf)
{
	inf->ptr.i_open = mlx_xpm_file_to_image(inf->ptr.mlx,
		"images/e.xpm", &inf->pixel, &inf->pixel);
	inf->ptr.i_dead = mlx_xpm_file_to_image(inf->ptr.mlx,
		"images/dead.xpm", &inf->pixel, &inf->pixel);
	inf->ptr.i_lake = mlx_xpm_file_to_image(inf->ptr.mlx,
			"images/-.xpm", &inf->pixel, &inf->pixel);
	inf->ptr.i_floor = mlx_xpm_file_to_image(inf->ptr.mlx,
			"images/0.xpm", &inf->pixel, &inf->pixel);
	inf->ptr.i_plr = mlx_xpm_file_to_image(inf->ptr.mlx,
			"images/p.xpm", &inf->pixel, &inf->pixel);
	inf->ptr.i_exit = mlx_xpm_file_to_image(inf->ptr.mlx,
			"images/E.xpm", &inf->pixel, &inf->pixel);
	inf->ptr.i_wall = mlx_xpm_file_to_image(inf->ptr.mlx,
			"images/1.xpm", &inf->pixel, &inf->pixel);
	inf->ptr.i_col = mlx_xpm_file_to_image(inf->ptr.mlx,
			"images/C.xpm", &inf->pixel, &inf->pixel);
}

void	ifs(t_info *inf, int i, int j)
{
	if (inf->matrix[i][j] == '1')
		mlx_put_image_to_window(inf->ptr.mlx, inf->ptr.win_ptr, inf->ptr.i_wall,
			j * 64, i * 64);
	else if (inf->matrix[i][j] == 'c')
		mlx_put_image_to_window(inf->ptr.mlx, inf->ptr.win_ptr, inf->ptr.i_col,
			j * 64, i * 64);
	else if (inf->matrix[i][j] == '0')
		mlx_put_image_to_window(inf->ptr.mlx, inf->ptr.win_ptr, inf->ptr.i_lake,
			j * 64, i * 64);
	else if (inf->matrix[i][j] == 'e')
		mlx_put_image_to_window(inf->ptr.mlx, inf->ptr.win_ptr, inf->ptr.i_exit,
			j * 64, i * 64);
	else if (inf->matrix[i][j] == 'E')
		mlx_put_image_to_window(inf->ptr.mlx, inf->ptr.win_ptr, inf->ptr.i_open,
			j * 64, i * 64);
	else if (inf->matrix[i][j] == 'C')
		mlx_put_image_to_window(inf->ptr.mlx, inf->ptr.win_ptr, inf->ptr.i_dead,
			j * 64 + 15, i * 64 + 15);
	else
		mlx_put_image_to_window(inf->ptr.mlx, inf->ptr.win_ptr,
			inf->ptr.i_floor, j * 64, i * 64);
}

void	img_to_window(t_info *inf)
{
	inf->i = 0;
	while (inf->i < inf->map.height)
	{
		inf->j = 0;
		while (inf->j < inf->map.width)
		{
			ifs(inf, inf->i, inf->j);
			inf->j++;
		}
		inf->i++;
	}
}

void	img_render(t_info *inf)
{
	ifs(inf, (inf->plr.p_y / 64), (inf->plr.p_x / 64));
	ifs(inf, (inf->plr.p_y / 64), (inf->plr.p_x / 64) + 1);
	ifs(inf, ((inf->plr.p_y / 64) + 1), (inf->plr.p_x / 64));
	ifs(inf, ((inf->plr.p_y / 64) + 1), ((inf->plr.p_x / 64) + 1));
	if (inf->map.food == 0)
		inf->matrix[inf->map.end_y][inf->map.end_x] = 'E';
	ifs(inf, inf->map.end_y, inf->map.end_x);
}