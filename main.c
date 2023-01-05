/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandrad <miandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:24:26 by miandrad          #+#    #+#             */
/*   Updated: 2023/01/05 18:05:05 by miandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_long.h"

int	close_com(t_ptr *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	exit (0);
}

void	gameinit(t_ptr *game)
{
	game->m_hgt = 0;
	game->m_wdt = 0;
	game->a = 0;
	game->d = 0;
	game->s = 0;
	game->w = 0;
	game->mlx_ptr = NULL;
	game->win_ptr = NULL;
}

int	main(int argc, char **argv)
{
	t_ptr	*inf;
	char	**map;
	int		i;
	int		fd;

	i = 0;
	inf = malloc(sizeof(t_ptr));
	gameinit(inf);
	fd = open(argv[1], O_RDONLY);
	map = map_cpy(fd, inf, argv[1]);
	while (map[i])
	{
		printf("%s", map[i]);
		i++;
	}
	if (wall_check(map, inf))
		printf("Yey, Deste lhe forte\n");
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

