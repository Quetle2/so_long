/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandrad <miandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:24:26 by miandrad          #+#    #+#             */
/*   Updated: 2023/01/10 18:01:22 by miandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_long.h"

int	close_com(t_info *inf)
{
	mlx_destroy_window(inf->ptr.mlx_ptr, inf->ptr.win_ptr);
	mlx_destroy_display(inf->ptr.mlx_ptr);
	free(inf->ptr.mlx_ptr);
	exit (0);
}

void	gameinit(t_info *inf)
{
	inf->map.height = 0;
	inf->map.width = 0;
	inf->map.food = 0;
	inf->plr.a = 0;
	inf->plr.d = 0;
	inf->plr.s = 0;
	inf->plr.w = 0;
	inf->ptr.mlx_ptr = NULL;
	inf->ptr.win_ptr = NULL;
	inf->index = 0;
}

int	main(int argc, char **argv)
{
	t_info	*inf;
	char	**map;
	int		fd;

	inf = malloc(sizeof(t_info));
	gameinit(inf);
	fd = open(argv[1], O_RDONLY);
	map = map_cpy(fd, inf, argv[1]);
	if (wall_check(map, inf))
		printf("Yey, Deste lhe forte\n");
	inf->index = 0;
	while (map[inf->index])
	{
		printf("%s", map[inf->index]);
		inf->index++;
	}
	inf->ptr.mlx_ptr = mlx_init();
	inf->ptr.win_ptr = mlx_new_window(inf->ptr.mlx_ptr, 1000, 800, "ola");
	if (!inf->ptr.win_ptr)
	{
		free (inf->ptr.mlx_ptr);
		return (0);
	}
	mlx_hook(inf->ptr.win_ptr, 2, 1L << 0, keydown, &inf);
	mlx_hook(inf->ptr.win_ptr, 3, 1L << 1, keyup, &inf);
	mlx_hook(inf->ptr.win_ptr, 17, 1L << 17, close_com, &inf);
	mlx_loop_hook(inf->ptr.mlx_ptr, walkying, &inf);
	mlx_loop(inf->ptr.mlx_ptr);
}
