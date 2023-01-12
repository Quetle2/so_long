/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandrad <miandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:34:07 by miandrad          #+#    #+#             */
/*   Updated: 2023/01/12 15:14:36 by miandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_long.h"

void	sprite_atribution(t_info *inf)
{
	inf->ptr.i_floor = mlx_xpm_file_to_image(inf->ptr.mlx, "images/0.xpm", &inf->pixel, &inf->pixel);
	inf->ptr.i_plr = mlx_xpm_file_to_image(inf->ptr.mlx, "images/bitfuul_image(1).xpm", &inf->pixel, &inf->pixel);
}
