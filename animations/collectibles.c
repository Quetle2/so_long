/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectibles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandrad <miandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:56:47 by ubuntu            #+#    #+#             */
/*   Updated: 2023/01/16 11:58:12 by miandrad         ###   ########.fr       */
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
