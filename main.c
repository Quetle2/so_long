/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandrad <miandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:24:26 by miandrad          #+#    #+#             */
/*   Updated: 2023/01/04 16:39:40 by miandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_long.h"

void	close_com(t_ptr *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	exit (0);
}

void	gameinit(t_ptr *game)
{
	game->a = 0;
	game->d = 0;
	game->s = 0;
	game->w = 0;
	game->mlx_ptr = NULL;
	game->win_ptr = NULL;
}

int	main(void)
{
	t_ptr	*inf;

	inf = malloc(sizeof(t_ptr));
	gameinit(inf);
	inf->mlx_ptr = mlx_init();
	inf->win_ptr = mlx_new_window(inf->mlx_ptr, 1000, 800, "ola");
	if (!inf->win_ptr)
	{
		free (inf->mlx_ptr);
		return (0);
	}
	mlx_hook(inf->win_ptr, 2, 1L << 0, keydown, &inf);
	mlx_hook(inf->win_ptr, 3, 1L << 1, keyup, &inf);
	mlx_hook(inf->win_ptr, 17, 1L << 17, close_com, &inf);
	mlx_loop_hook(inf->mlx_ptr, walkying, &inf);
	mlx_loop(inf->mlx_ptr);
}

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
		write(1, "a", 1);
	if (plr_m->w == 1)
		write(1, "w", 1);
	if (plr_m->s == 1)
		write(1, "s", 1);
	if (plr_m->d == 1)
		write(1, "d", 1);
	return (0);
}
