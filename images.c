/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandrad <miandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:34:07 by miandrad          #+#    #+#             */
/*   Updated: 2023/01/13 19:09:16 by miandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_long.h"

void	sprite_atribution(t_info *inf)
{
	inf->ptr.i_lake = mlx_xpm_file_to_image(inf->ptr.mlx,
			"images/-.xpm", &inf->pixel, &inf->pixel);
	inf->ptr.i_floor = mlx_xpm_file_to_image(inf->ptr.mlx,
			"images/0.xpm", &inf->pixel, &inf->pixel);
	inf->ptr.i_plr = mlx_xpm_file_to_image(inf->ptr.mlx,
			"images/P.xpm", &inf->pixel, &inf->pixel);
	inf->ptr.i_exit = mlx_xpm_file_to_image(inf->ptr.mlx,
			"images/E.xpm", &inf->pixel, &inf->pixel);
	inf->ptr.i_wall = mlx_xpm_file_to_image(inf->ptr.mlx,
			"images/1.xpm", &inf->pixel, &inf->pixel);
	inf->ptr.i_col = mlx_xpm_file_to_image(inf->ptr.mlx,
			"images/C.xpm", &inf->pixel, &inf->pixel);
}

void	ifs(t_info *inf)
{
	if (inf->matrix[inf->i][inf->j] == '1')
		mlx_put_image_to_window(inf->ptr.mlx, inf->ptr.win_ptr, inf->ptr.i_wall,
			inf->j * 64, inf->i * 64);
	else if (inf->matrix[inf->i][inf->j] == 'c')
		mlx_put_image_to_window(inf->ptr.mlx, inf->ptr.win_ptr, inf->ptr.i_col,
			inf->j * 64, inf->i * 64);
	else if (inf->matrix[inf->i][inf->j] == '0')
		mlx_put_image_to_window(inf->ptr.mlx, inf->ptr.win_ptr, inf->ptr.i_lake,
			inf->j * 64, inf->i * 64);
	else if (inf->matrix[inf->i][inf->j] == 'e')
		mlx_put_image_to_window(inf->ptr.mlx, inf->ptr.win_ptr, inf->ptr.i_exit,
			inf->j * 64, inf->i * 64);
	else
		mlx_put_image_to_window(inf->ptr.mlx, inf->ptr.win_ptr,
			inf->ptr.i_floor, inf->j * 64, inf->i * 64);
}

void	img_to_window(t_info *inf)
{
	inf->i = 0;
	while (inf->i < inf->map.height)
	{
		inf->j = 0;
		while (inf->j < inf->map.width)
		{
			mlx_put_image_to_window(inf->ptr.mlx,
				inf->ptr.win_ptr, inf->ptr.i_floor,
				inf->j * 64, inf->i * 64);
			ifs(inf);
			inf->j++;
		}
		inf->i++;
	}
}

// void	img_render(t_info *inf)
// {
// 	inf->i = 0;
// 	while (inf->i < inf->map.height)
// 	{
// 		inf->j = 0;
// 		while (inf->j < inf->map.width)
// 		{
// 			if (inf->matrix[inf->i][inf->j] != '1'
// 			&& inf->matrix[inf->i][inf->j] != 'c'
// 			&& inf->matrix[inf->i][inf->j] != 'e'
// 			&& inf->matrix[inf->i][inf->j] != '0')
// 				mlx_put_image_to_window(inf->ptr.mlx, inf->ptr.win_ptr,
// 					inf->ptr.i_floor, inf->j * 64, inf->i * 64);
// 			inf->j++;
// 		}
// 		inf->i++;
// 	}
// }

void	img_render(t_info *inf)
{

	mlx_put_image_to_window(inf->ptr.mlx, inf->ptr.win_ptr,
		inf->ptr.i_floor, (inf->plr.p_x / 64) * 64, (inf->plr.p_y / 64) * 64);
	mlx_put_image_to_window(inf->ptr.mlx, inf->ptr.win_ptr,
		inf->ptr.i_floor, ((inf->plr.p_x / 64) + 1) * 64, (inf->plr.p_y / 64) * 64);
	mlx_put_image_to_window(inf->ptr.mlx, inf->ptr.win_ptr,
		inf->ptr.i_floor, (inf->plr.p_x / 64) * 64, ((inf->plr.p_y / 64) + 1) * 64);
	mlx_put_image_to_window(inf->ptr.mlx, inf->ptr.win_ptr,
		inf->ptr.i_floor, ((inf->plr.p_x / 64) + 1) * 64, ((inf->plr.p_y / 64) + 1) * 64);

}
