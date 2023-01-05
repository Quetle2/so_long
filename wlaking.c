/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wlaking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandrad <miandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:45:22 by miandrad          #+#    #+#             */
/*   Updated: 2023/01/05 14:47:05 by miandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_long.h"

int	keydown(int keycode, t_ptr *plr_m)
{
	if (keycode == 'a')
		plr_m->a = 1;
	else if (keycode == 'w')
		plr_m->w = 1;
	else if (keycode == 's')
		plr_m->s = 1;
	else if (keycode == 'd')
		plr_m->d = 1;
	else if (keycode == 65307)
		close_com(plr_m);
	return (0);
}

int	keyup(int keycode, t_ptr *plr_m)
{
	if (keycode == 'a')
		plr_m->a = 0;
	if (keycode == 'w')
		plr_m->w = 0;
	if (keycode == 's')
		plr_m->s = 0;
	if (keycode == 'd')
		plr_m->d = 0;
	return (0);
}

int	walkying(t_ptr *plr_m)
{
	if (plr_m->a == 1)
		write(1, "A", 1);
	if (plr_m->w == 1)
		write(1, "W", 1);
	if (plr_m->s == 1)
		write(1, "S", 1);
	if (plr_m->d == 1)
		write(1, "D", 1);
	return (0);
}
