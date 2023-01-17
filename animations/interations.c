/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandrad <miandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:56:47 by ubuntu            #+#    #+#             */
/*   Updated: 2023/01/17 16:03:39 by miandrad         ###   ########.fr       */
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
	if (inf->matrix[((inf->plr.p_y + 19) / 64)][(inf->plr.p_x / 64)] == 'c')
		{
			inf->map.food--;
			inf->matrix[((inf->plr.p_y + 19) / 64)][(inf->plr.p_x / 64)] = 'C';
		}
	if (inf->matrix[((inf->plr.p_y + 39) / 64)][((inf->plr.p_x + 19) / 64)] == 'c')
		{
			inf->map.food--;
			inf->matrix[((inf->plr.p_y + 39) / 64)][((inf->plr.p_x + 19) / 64)] = 'C';
		}
	if (inf->matrix[((inf->plr.p_y + 39) / 64)][((inf->plr.p_x + 19) / 64)] == 'c')
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
		}
	if (inf->matrix[((inf->plr.p_y + 19) / 64)][(inf->plr.p_x / 64)] == 'E')
		{
			mlx_string_put(inf->ptr.mlx, inf->ptr.win_ptr, 100, 100, 255, "PARABIENS");
		}
	if (inf->matrix[((inf->plr.p_y + 39) / 64)][((inf->plr.p_x + 19) / 64)] == 'E')
		{
			mlx_string_put(inf->ptr.mlx, inf->ptr.win_ptr, 100, 100, 255, "PARABIENS");
		}
	if (inf->matrix[((inf->plr.p_y + 39) / 64)][((inf->plr.p_x + 19) / 64)] == 'E')
		{
			mlx_string_put(inf->ptr.mlx, inf->ptr.win_ptr, 100, 100, 255, "PARABIENS");
		}
}
