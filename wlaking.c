/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wlaking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandrad <miandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:45:22 by miandrad          #+#    #+#             */
/*   Updated: 2023/01/19 15:45:01 by miandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_long.h"

int	keydown(int keycode, t_info *inf)
{
	if (keycode == 'a')
		inf->plr.a = 1;
	else if (keycode == 'w')
		inf->plr.w = 1;
	else if (keycode == 's')
		inf->plr.s = 1;
	else if (keycode == 'd')
		inf->plr.d = 1;
	else if (keycode == 65307)
		close_com(inf);
	return (0);
}

int	keyup(int keycode, t_info *inf)
{
	if (keycode == 'a')
		inf->plr.a = 0;
	if (keycode == 'w')
		inf->plr.w = 0;
	if (keycode == 's')
		inf->plr.s = 0;
	if (keycode == 'd')
		inf->plr.d = 0;
	return (0);
}

int	walkying(t_info *inf)
{
	// mlx_clear_window(inf->ptr.mlx, inf->ptr.win_ptr);
	if (inf->end == 0)
	{
		img_render(inf);
		if (inf->plr.a == 1
			&& inf->matrix[(inf->plr.p_y / 64)]
			[((inf->plr.p_x - 1) / 64)] != '1'
			&& inf->matrix[((inf->plr.p_y + 39) / 64)]
			[((inf->plr.p_x - 1) / 64)] != '1')
			inf->plr.p_x--;
		if (inf->plr.w == 1
			&& inf->matrix[((inf->plr.p_y - 1) / 64)]
			[(inf->plr.p_x / 64)] != '1'
			&& inf->matrix[((inf->plr.p_y - 1) / 64)]
			[((inf->plr.p_x + 39) / 64)] != '1')
			inf->plr.p_y--;
		if (inf->plr.s == 1
			&& inf->matrix[((inf->plr.p_y + 40) / 64)]
			[(inf->plr.p_x / 64)] != '1'
			&& inf->matrix[((inf->plr.p_y + 40) / 64)]
			[((inf->plr.p_x + 39) / 64)] != '1')
			inf->plr.p_y++;
		if (inf->plr.d == 1
			&& inf->matrix[(inf->plr.p_y / 64)]
			[((inf->plr.p_x + 40) / 64)] != '1'
			&& inf->matrix[((inf->plr.p_y + 39) / 64)]
			[((inf->plr.p_x + 40) / 64)] != '1')
			inf->plr.p_x++;
		colect_food(inf);
		mlx_put_image_to_window(inf->ptr.mlx, inf->ptr.win_ptr,
			inf->ptr.i_plr, inf->plr.p_x, inf->plr.p_y);
		animation(inf);
		end_check(inf);
	}
	else if (inf->end == 1)
		work(inf);
	return (0);
}
