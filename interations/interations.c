/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandrad <miandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:23:21 by miandrad          #+#    #+#             */
/*   Updated: 2023/01/23 16:23:20 by miandrad         ###   ########.fr       */
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

void	display_victory(t_info inf)
{
	mlx_clear_window(inf.ptr.mlx, inf.ptr.win_ptr);
	mlx_destroy_window(inf.ptr.mlx, inf.ptr.win_ptr);
	inf.ptr.win_ptr = NULL;
	inf.ptr.win_ptr2 = mlx_new_window(inf.ptr.mlx,
			1500, 1500, "Congratulations !");
	mlx_put_image_to_window(inf.ptr.mlx, inf.ptr.win_ptr2, inf.ptr.i_win,
		0, 0);
	mlx_hook(inf.ptr.win_ptr2, 2, 1L << 0, keydown, &inf);
	mlx_hook(inf.ptr.win_ptr2, 17, 1L << 17, close_com, &inf);
	mlx_loop(inf.ptr.mlx);
}

void	enemy_check(t_info *inf)
{
	if (inf->matrix[(inf->plr.p_y / 64)][((inf->plr.p_x + 19) / 64)] == 'G')
	{
		ft_printf("\nYou dead\n");
		close_com(inf);
	}
	if (inf->matrix[((inf->plr.p_y + 19) / 64)]
		[(inf->plr.p_x / 64)] == 'G')
	{
		ft_printf("\nYou dead\n");
		close_com(inf);
	}
	if (inf->matrix[((inf->plr.p_y + 39) / 64)]
		[((inf->plr.p_x + 19) / 64)] == 'G')
	{
		ft_printf("\nYou dead\n");
		close_com(inf);
	}
	if (inf->matrix[((inf->plr.p_y + 39) / 64)]
		[((inf->plr.p_x + 19) / 64)] == 'G')
	{
		ft_printf("\nYou dead\n");
		close_com(inf);
	}
}
