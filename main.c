/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandrad <miandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:24:26 by miandrad          #+#    #+#             */
/*   Updated: 2023/01/12 15:16:03 by miandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_long.h"

int	close_com(t_info *inf)
{
	mlx_destroy_image(inf->ptr.mlx, inf->ptr.i_floor);
	mlx_destroy_window(inf->ptr.mlx, inf->ptr.win_ptr);
	mlx_destroy_display(inf->ptr.mlx);
	free(inf->ptr.mlx);
	free(inf->matrix);
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
	inf->plr.x = 0;
	inf->plr.y = 0;
	inf->plr.p_x = 0;
	inf->plr.p_y = 0;
	inf->ptr.mlx = NULL;
	inf->ptr.win_ptr = NULL;
	inf->ptr.i_floor = NULL;
	inf->i = 0;
	inf->j = 0;
	inf->pixel = 64;
}

int	main(int argc, char **argv)
{
	t_info	inf;
	int		fd;

	if (argc != 2)
		return (0);
	gameinit(&inf);
	fd = open(argv[1], O_RDONLY);
	inf.matrix = map_cpy(fd, &inf, argv[1]);
	if (wall_check(&inf))
		ft_printf("Yey, Deste lhe forte\n");
	ft_printf("%d %d \n", inf.plr.x, inf.plr.y);
	inf.plr.p_x = inf.plr.x * 64;
	inf.plr.p_y = inf.plr.y * 64;
	ft_printf("%d %d \n", inf.plr.p_x, inf.plr.p_y);
	inf.i = 0;
	while (inf.matrix[inf.i])
	{
		ft_printf("%s", inf.matrix[inf.i]);
		inf.i++;
	}
	sprite_atribution(&inf);
	inf.ptr.mlx = mlx_init();
	inf.ptr.win_ptr = mlx_new_window(inf.ptr.mlx, (inf.map.width) * 64,
			(inf.map.height) * 64, "ola");
	inf.ptr.i_floor = mlx_new_image(inf.ptr.mlx, (inf.map.width) * 64,
			(inf.map.height) * 64);
	if (!inf.ptr.win_ptr)
	{
		free (inf.ptr.mlx);
		return (0);
	}
	mlx_hook(inf.ptr.win_ptr, 2, 1L << 0, keydown, &inf);
	mlx_hook(inf.ptr.win_ptr, 3, 1L << 1, keyup, &inf);
	mlx_hook(inf.ptr.win_ptr, 17, 1L << 17, close_com, &inf);
	mlx_loop_hook(inf.ptr.mlx, walkying, &inf);
	mlx_loop(inf.ptr.mlx);
}

void	img_to_window(t_info *inf)
{
	inf->i = 0;
	while (inf->i < (inf->map.height))
	{
		inf->j = 0;
		while (inf->j < inf->map.width)
		{
			mlx_put_image_to_window(inf->ptr.mlx, inf->ptr.win_ptr, inf->ptr.i_floor, inf->j * 64, inf->i * 64);
			inf->j++;
		}
		inf->i++;
	}
}