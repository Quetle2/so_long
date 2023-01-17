/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandrad <miandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:45:23 by miandrad          #+#    #+#             */
/*   Updated: 2023/01/16 21:28:37 by miandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../So_long.h"

void	animation(t_info *inf)
{
	if (inf->plr.a == 1 && inf->plr.w == 0 && inf->plr.s == 0)
		mlx_put_image_to_window(inf->ptr.mlx, inf->ptr.win_ptr,
			inf->ptr.i_pl, inf->plr.p_x, inf->plr.p_y);
	if (inf->plr.w == 1 && inf->plr.d == 0 && inf->plr.a == 0)
		mlx_put_image_to_window(inf->ptr.mlx, inf->ptr.win_ptr,
			inf->ptr.i_pu, inf->plr.p_x, inf->plr.p_y);
	if (inf->plr.s == 1 && inf->plr.d == 0 && inf->plr.a == 0)
		mlx_put_image_to_window(inf->ptr.mlx, inf->ptr.win_ptr,
			inf->ptr.i_plr, inf->plr.p_x, inf->plr.p_y);
	if (inf->plr.d == 1 && inf->plr.w == 0 && inf->plr.s == 0)
		mlx_put_image_to_window(inf->ptr.mlx, inf->ptr.win_ptr,
			inf->ptr.i_pd, inf->plr.p_x, inf->plr.p_y);
	if (inf->plr.a == 1 && inf->plr.w == 1 && inf->plr.s == 0)
		mlx_put_image_to_window(inf->ptr.mlx, inf->ptr.win_ptr,
			inf->ptr.i_pul, inf->plr.p_x, inf->plr.p_y);
	if (inf->plr.a == 1 && inf->plr.w == 0 && inf->plr.s == 1)
		mlx_put_image_to_window(inf->ptr.mlx, inf->ptr.win_ptr,
			inf->ptr.i_psl, inf->plr.p_x, inf->plr.p_y);
	if (inf->plr.d == 1 && inf->plr.w == 1 && inf->plr.s == 0)
		mlx_put_image_to_window(inf->ptr.mlx, inf->ptr.win_ptr,
			inf->ptr.i_pud, inf->plr.p_x, inf->plr.p_y);
	if (inf->plr.d == 1 && inf->plr.w == 0 && inf->plr.s == 1)
		mlx_put_image_to_window(inf->ptr.mlx, inf->ptr.win_ptr,
			inf->ptr.i_psd, inf->plr.p_x, inf->plr.p_y);
}
