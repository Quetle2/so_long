/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandrad <miandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:56:47 by ubuntu            #+#    #+#             */
/*   Updated: 2023/01/17 19:05:39 by miandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../So_long.h"

void	colect_food(t_info *inf)
{
	if (inf->matrix[(inf->plr.p_y / 64)][((inf->plr.p_x + 19) / 64)] == 'c')
		{
			inf->map.food--;
			inf->matrix[(inf->plr.p_y / 64)][((inf->plr.p_x + 39) / 64)] = 'C';
		}
	else if (inf->matrix[((inf->plr.p_y + 19) / 64)][(inf->plr.p_x / 64)] == 'c')
		{
			inf->map.food--;
			inf->matrix[((inf->plr.p_y + 19) / 64)][(inf->plr.p_x / 64)] = 'C';
		}
	else if (inf->matrix[((inf->plr.p_y + 39) / 64)][((inf->plr.p_x + 19) / 64)] == 'c')
		{
			inf->map.food--;
			inf->matrix[((inf->plr.p_y + 39) / 64)][((inf->plr.p_x + 19) / 64)] = 'C';
		}
	else if (inf->matrix[((inf->plr.p_y + 39) / 64)][((inf->plr.p_x + 19) / 64)] == 'c')
		{
			inf->map.food--;
			inf->matrix[(inf->plr.p_y / 64)][((inf->plr.p_x + 39) / 64)] = 'C';
		}
}

void	end_check(t_info *inf)
{
	if (inf->matrix[(inf->plr.p_y / 64)][((inf->plr.p_x + 19) / 64)] == 'E')
		{
			mlx_string_put(inf->ptr.mlx, inf->ptr.win_ptr, 100, 100, 255, "PARABIENS");
			inf->end = 1;
		}
	if (inf->matrix[((inf->plr.p_y + 19) / 64)][(inf->plr.p_x / 64)] == 'E')
		{
			mlx_string_put(inf->ptr.mlx, inf->ptr.win_ptr, 100, 100, 255, "PARABIENS");
			inf->end = 1;
		}
	if (inf->matrix[((inf->plr.p_y + 39) / 64)][((inf->plr.p_x + 19) / 64)] == 'E')
		{
			mlx_string_put(inf->ptr.mlx, inf->ptr.win_ptr, 100, 100, 255, "PARABIENS");
			inf->end = 1;
		}
	if (inf->matrix[((inf->plr.p_y + 39) / 64)][((inf->plr.p_x + 19) / 64)] == 'E')
		{
			mlx_string_put(inf->ptr.mlx, inf->ptr.win_ptr, 100, 100, 255, "PARABIENS");
			inf->end = 1;
		}
}

void	end_screen(t_info *inf)
{
	inf->end++;
	mlx_clear_window(inf->ptr.mlx, inf->ptr.win_ptr);
	mlx_destroy_window(inf->ptr.mlx, inf->ptr.win_ptr);
	inf->ptr.win_ptr = mlx_new_window(inf->ptr.mlx, 1500,
			1500, "ola");
	if (!inf->ptr.win_ptr)
	{
		free (inf->ptr.mlx);
		return ;
	}
	mlx_put_image_to_window(inf->ptr.mlx, inf->ptr.win_ptr, inf->ptr.i_win,
			0, 0);
	mlx_hook(inf->ptr.win_ptr, 2, 1L << 0, keydown, &inf);
	mlx_hook(inf->ptr.win_ptr, 17, 1L << 17, close_com, &inf);
	// mlx_loop(inf->ptr.mlx);
}

// int	close_io(t_info *inf)
// {
// 	int	i;

// 	i = 0;
// 	// mlx_destroy_image(inf->ptr.mlx, inf->ptr.i_col);
// 	// mlx_destroy_image(inf->ptr.mlx, inf->ptr.i_win);
// 	// mlx_destroy_image(inf->ptr.mlx, inf->ptr.i_lake);
// 	// mlx_destroy_image(inf->ptr.mlx, inf->ptr.i_floor);
// 	// mlx_destroy_image(inf->ptr.mlx, inf->ptr.i_exit);
// 	// mlx_destroy_image(inf->ptr.mlx, inf->ptr.i_wall);
// 	// mlx_destroy_image(inf->ptr.mlx, inf->ptr.i_plr);
// 	// mlx_destroy_image(inf->ptr.mlx, inf->ptr.i_pl);
// 	// mlx_destroy_image(inf->ptr.mlx, inf->ptr.i_pd);
// 	// mlx_destroy_image(inf->ptr.mlx, inf->ptr.i_pu);
// 	// mlx_destroy_image(inf->ptr.mlx, inf->ptr.i_psd);
// 	// mlx_destroy_image(inf->ptr.mlx, inf->ptr.i_psl);
// 	// mlx_destroy_image(inf->ptr.mlx, inf->ptr.i_pud);
// 	// mlx_destroy_image(inf->ptr.mlx, inf->ptr.i_pul);
// 	// mlx_destroy_image(inf->ptr.mlx, inf->ptr.i_dead);
// 	// mlx_destroy_image(inf->ptr.mlx, inf->ptr.i_open);
// 	mlx_clear_window(inf->ptr.mlx, inf->ptr.win_ptr);
// 	mlx_destroy_window(inf->ptr.mlx, inf->ptr.win_ptr);
// 	mlx_destroy_display(inf->ptr.mlx);
// 	free(inf->ptr.mlx);
// 	while (inf->matrix[i])
// 	{
// 		free(inf->matrix[i]);
// 		i++;
// 	}
// 	get_next_line(-1);
// 	free(inf->matrix[i]);
// 	free(inf->matrix);
// 	write(1, "\nGAME OVER\n\n", 12);
// 	exit(0);
// }
