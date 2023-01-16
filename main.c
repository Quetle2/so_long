/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:24:26 by miandrad          #+#    #+#             */
/*   Updated: 2023/01/15 23:06:05 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_long.h"

int	close_com(t_info *inf)
{
	int	i;

	i = 0;
	mlx_destroy_image(inf->ptr.mlx, inf->ptr.i_col);
	mlx_destroy_image(inf->ptr.mlx, inf->ptr.i_floor);
	mlx_destroy_image(inf->ptr.mlx, inf->ptr.i_exit);
	mlx_destroy_image(inf->ptr.mlx, inf->ptr.i_wall);
	mlx_destroy_image(inf->ptr.mlx, inf->ptr.i_plr);
	mlx_clear_window(inf->ptr.mlx, inf->ptr.win_ptr);
	mlx_destroy_window(inf->ptr.mlx, inf->ptr.win_ptr);
	mlx_destroy_display(inf->ptr.mlx);
	free(inf->ptr.mlx);
	while (inf->matrix[i])
	{
		free(inf->matrix[i]);
		i++;
	}
	get_next_line(-1);
	free(inf->matrix[i]);
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
	inf.i = 0;
	inf.plr.p_x = inf.plr.x * 64;
	inf.plr.p_y = inf.plr.y * 64;
	while (inf.matrix[inf.i])
	{
		ft_printf("%s", inf.matrix[inf.i]);
		inf.i++;
	}
	inf.ptr.mlx = mlx_init();
	inf.ptr.win_ptr = mlx_new_window(inf.ptr.mlx, (inf.map.width) * 64,
			(inf.map.height) * 64, "ola");
	if (!inf.ptr.win_ptr)
	{
		free (inf.ptr.mlx);
		return (0);
	}
	sprite_atribution(&inf);
	img_to_window(&inf);
	mlx_hook(inf.ptr.win_ptr, 2, 1L << 0, keydown, &inf);
	mlx_hook(inf.ptr.win_ptr, 3, 1L << 1, keyup, &inf);
	mlx_hook(inf.ptr.win_ptr, 17, 1L << 17, close_com, &inf);
	mlx_loop_hook(inf.ptr.mlx, walkying, &inf);
	mlx_loop(inf.ptr.mlx);
}
