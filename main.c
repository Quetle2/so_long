/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandrad <miandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:23:08 by miandrad          #+#    #+#             */
/*   Updated: 2023/01/19 15:41:43 by miandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "So_long.h"

int	close_com(t_info *inf)
{
	int	i;

	i = 0;
	mlx_destroy_image(inf->ptr.mlx, inf->ptr.i_win);
	mlx_destroy_image(inf->ptr.mlx, inf->ptr.i_col);
	mlx_destroy_image(inf->ptr.mlx, inf->ptr.i_lake);
	mlx_destroy_image(inf->ptr.mlx, inf->ptr.i_floor);
	mlx_destroy_image(inf->ptr.mlx, inf->ptr.i_exit);
	mlx_destroy_image(inf->ptr.mlx, inf->ptr.i_wall);
	mlx_destroy_image(inf->ptr.mlx, inf->ptr.i_plr);
	mlx_destroy_image(inf->ptr.mlx, inf->ptr.i_pl);
	mlx_destroy_image(inf->ptr.mlx, inf->ptr.i_pd);
	mlx_destroy_image(inf->ptr.mlx, inf->ptr.i_pu);
	mlx_destroy_image(inf->ptr.mlx, inf->ptr.i_psd);
	mlx_destroy_image(inf->ptr.mlx, inf->ptr.i_psl);
	mlx_destroy_image(inf->ptr.mlx, inf->ptr.i_pud);
	mlx_destroy_image(inf->ptr.mlx, inf->ptr.i_pul);
	mlx_destroy_image(inf->ptr.mlx, inf->ptr.i_dead);
	mlx_destroy_image(inf->ptr.mlx, inf->ptr.i_open);
	// mlx_clear_window(inf->ptr.mlx, inf->ptr.win_ptr);
	// mlx_destroy_window(inf->ptr.mlx, inf->ptr.win_ptr);
	// mlx_destroy_display(inf->ptr.mlx);
	mlx_clear_window(inf->ptr.mlx2, inf->ptr.win_ptr2);
	mlx_destroy_window(inf->ptr.mlx2, inf->ptr.win_ptr2);
	mlx_destroy_display(inf->ptr.mlx2);
	free(inf->ptr.mlx);
	free(inf->ptr.mlx2);
	while (inf->matrix[i])
	{
		free(inf->matrix[i]);
		i++;
	}
	get_next_line(-1);
	free(inf->matrix[i]);
	free(inf->matrix);
	write(1, "\nGAME OVER\n\n", 12);
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
	inf->end = 0;
	inf->pixel = 64;
	inf->win_final = 1500;
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
