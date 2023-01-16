/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandrad <miandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:45:23 by miandrad          #+#    #+#             */
/*   Updated: 2023/01/16 13:47:30 by miandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../So_long.h"

void	animation(t_info *inf)
{
	if (inf->plr.a == 1)
		mlx_put_image_to_window(inf->ptr.mlx, inf->ptr.win_ptr,
			inf->ptr.i_pl, inf->plr.p_x, inf->plr.p_y);
	if (inf->plr.w == 1)
		mlx_put_image_to_window(inf->ptr.mlx, inf->ptr.win_ptr,
			inf->ptr.i_pu, inf->plr.p_x, inf->plr.p_y);
	if (inf->plr.s == 1)
		mlx_put_image_to_window(inf->ptr.mlx, inf->ptr.win_ptr,
			inf->ptr.i_plr, inf->plr.p_x, inf->plr.p_y);
	if (inf->plr.d == 1)
		mlx_put_image_to_window(inf->ptr.mlx, inf->ptr.win_ptr,
			inf->ptr.i_pd, inf->plr.p_x, inf->plr.p_y);
}
