/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandrad <miandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:23:21 by miandrad          #+#    #+#             */
/*   Updated: 2023/01/18 16:29:01 by miandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../So_long.h"

void	colect_food(t_info *inf)
{
	if (inf->matrix[(inf->plr.p_y / 64)][((inf->plr.p_x + 19) / 64)] == 'c')
	{
		inf->map.food--;
		inf->matrix[(inf->plr.p_y / 64)][((inf->plr.p_x + 19) / 64)] = 'C';
	}
	else if (inf->matrix[((inf->plr.p_y + 19) / 64)]
		[(inf->plr.p_x / 64)] == 'c')
	{
		inf->map.food--;
		inf->matrix[((inf->plr.p_y + 19) / 64)][(inf->plr.p_x / 64)] = 'C';
	}
	else if (inf->matrix[((inf->plr.p_y + 39) / 64)]
		[((inf->plr.p_x + 19) / 64)] == 'c')
	{
		inf->map.food--;
		inf->matrix[((inf->plr.p_y + 39) / 64)]
		[((inf->plr.p_x + 19) / 64)] = 'C';
	}
	else if (inf->matrix[((inf->plr.p_y + 39) / 64)]
		[((inf->plr.p_x + 19) / 64)] == 'c')
	{
		inf->map.food--;
		inf->matrix[((inf->plr.p_y + 39) / 64)]
		[((inf->plr.p_x + 19) / 64)] = 'C';
	}
}

void	end_check(t_info *inf)
{
	if (inf->matrix[(inf->plr.p_y / 64)][((inf->plr.p_x + 19) / 64)] == 'E')
		inf->end = 1;
	if (inf->matrix[((inf->plr.p_y + 19) / 64)][(inf->plr.p_x / 64)] == 'E')
		inf->end = 1;
	if (inf->matrix[((inf->plr.p_y + 39) / 64)]
		[((inf->plr.p_x + 19) / 64)] == 'E')
		inf->end = 1;
	if (inf->matrix[((inf->plr.p_y + 39) / 64)]
		[((inf->plr.p_x + 19) / 64)] == 'E')
		inf->end = 1;
}

void	end_screen(t_info inf)
{
	inf.end++;
	free (inf.ptr.mlx);
	inf.ptr.mlx = mlx_init();
	mlx_clear_window(inf.ptr.mlx, inf.ptr.win_ptr);
	mlx_destroy_window(inf.ptr.mlx, inf.ptr.win_ptr);
	inf.ptr.win_ptr = mlx_new_window(inf.ptr.mlx, 1500,
			1500, "ola");
	if (!inf.ptr.win_ptr)
	{
		free (inf.ptr.mlx);
		return ;
	}
	mlx_put_image_to_window(inf.ptr.mlx, inf.ptr.win_ptr, inf.ptr.i_win,
		0, 0);
	mlx_hook(inf.ptr.win_ptr, 2, 1L << 0, keydown, &inf);
	mlx_hook(inf.ptr.win_ptr, 17, 1L << 17, end_game, &inf);
	mlx_loop(inf.ptr.mlx);
}

void	close_io(t_info *inf)
{
	free (inf->ptr.mlx);
	mlx_clear_window(inf->ptr.mlx, inf->ptr.win_ptr);
	mlx_destroy_window(inf->ptr.mlx, inf->ptr.win_ptr);
	end_screen(*inf);
}

void	close_first_window(t_info *inf)
{
	int	i;

	mlx_destroy_image(inf->ptr.mlx, inf->ptr.i_col);
	mlx_destroy_image(inf->ptr.mlx, inf->ptr.i_lake);
	mlx_destroy_image(inf->ptr.mlx, inf->ptr.i_floor);
	mlx_destroy_image(inf->ptr.mlx, inf->ptr.i_exit);
	mlx_destroy_image(inf->ptr.mlx, inf->ptr.i_wall);
	mlx_destroy_image(inf->ptr.mlx, inf->ptr.i_plr);
	mlx_destroy_image(inf->ptr.mlx, inf->ptr.i_pl);
	mlx_destroy_image(inf->ptr.mlx, inf->ptr.i_pd);
	mlx_destroy_image(inf->ptr.mlx, inf->ptr.i_pu);
	mlx_destroy_image(inf->ptr.mlx, inf->ptr.i_psd);
	mlx_destroy_image(inf->ptr.mlx, inf->ptr.i_psl);
	mlx_destroy_image(inf->ptr.mlx, inf->ptr.i_pud);
	mlx_destroy_image(inf->ptr.mlx, inf->ptr.i_pul);
	mlx_destroy_image(inf->ptr.mlx, inf->ptr.i_dead);
	mlx_destroy_image(inf->ptr.mlx, inf->ptr.i_open);
	free(inf->ptr.mlx);
	i = 0;
	while (inf->matrix[i])
	{
		free(inf->matrix[i]);
		i++;
	}
	get_next_line(-1);
	free (inf->matrix[i]);
	free (inf->matrix);
	display_victory(*inf);
}

void	display_victory(t_info inf)
{
	inf.end++;
	inf.ptr.mlx = mlx_init();
	mlx_clear_window(inf.ptr.mlx, inf.ptr.win_ptr);
	mlx_destroy_window(inf.ptr.mlx, inf.ptr.win_ptr);
	inf.ptr.win_ptr = mlx_new_window(inf.ptr.mlx, 1000, 560, "Congratulations !");
	if (!inf.ptr.win_ptr)
	{
		free (inf.ptr.mlx);
		return ;
	}
	mlx_put_image_to_window(inf.ptr.mlx, inf.ptr.win_ptr, inf.ptr.i_win,
		0, 0);
	mlx_hook(inf.ptr.win_ptr, 2, 1L << 0, keydown, &inf);
	mlx_hook(inf.ptr.win_ptr, 17, 1L << 17, end_game, &inf);
	mlx_loop(inf.ptr.mlx);
}

int	end_game(t_info *inf)
{
	mlx_destroy_image(inf->ptr.mlx, inf->ptr.i_win);
	mlx_clear_window(inf->ptr.mlx, inf->ptr.win_ptr);
	mlx_destroy_window(inf->ptr.mlx, inf->ptr.win_ptr);
	mlx_destroy_display(inf->ptr.mlx);
	free(inf->ptr.mlx);
	exit (0);
}
