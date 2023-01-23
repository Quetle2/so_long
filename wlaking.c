/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wlaking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandrad <miandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:45:22 by miandrad          #+#    #+#             */
/*   Updated: 2023/01/20 17:23:19 by miandrad         ###   ########.fr       */
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
	char	*mov;

	if (inf->end == 0)
	{
		inf->steps++;
		mov = ft_itoa(inf->steps);
		walkying_helper(inf);
		mlx_string_put(inf->ptr.mlx, inf->ptr.win_ptr,
			(((inf->map.width - 2) * 64) - 32),
			(inf->map.height * 64) - 26, 11111111, "NUMBER OF MOVEMENTS : ");
		mlx_string_put(inf->ptr.mlx, inf->ptr.win_ptr,
			((inf->map.width * 64) - 25),
			(inf->map.height * 64) - 26, 11111111, mov);
		colect_food(inf);
		mlx_put_image_to_window(inf->ptr.mlx, inf->ptr.win_ptr,
			inf->ptr.i_plr, inf->plr.p_x, inf->plr.p_y);
		animation(inf);
		end_check(inf);
		free(mov);
	}
	else if (inf->end == 1 && inf->end++)
	{
		display_victory(*inf);
	}
	return (0);
}
