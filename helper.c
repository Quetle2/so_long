/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandrad <miandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:31:16 by miandrad          #+#    #+#             */
/*   Updated: 2023/01/26 16:40:11 by miandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_long.h"

int	main_helper(t_info *inf, char **argv)
{
	int		fd;

	if (ft_strlen(argv[1]) < 4 || !ft_strnstr(argv[1] + ft_strlen(argv[1]) - 4,
			".ber", 4))
	{
		write(1, "\nError\nThe map file doesn't have the .ber extension\n\n", 54);
		return (0);
	}
	gameinit(inf);
	fd = open(argv[1], O_RDONLY);
	inf->matrix = map_cpy(fd, inf, argv[1]);
	if (!wall_check(inf))
	{
		ft_printf("\nError\nInvalid map\n");
		free_map(inf);
	}
	inf->i = 0;
	inf->plr.p_x = inf->plr.x * 64;
	inf->plr.p_y = inf->plr.y * 64;
	return (1);
}

void	close_com_helper(t_info *inf)
{
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
	if (inf->ptr.win_ptr)
	{
		mlx_clear_window(inf->ptr.mlx, inf->ptr.win_ptr);
		mlx_destroy_window(inf->ptr.mlx, inf->ptr.win_ptr);
	}
}

void	sprite_atribution_helper(t_info *inf)
{
	inf->ptr.i_plr = mlx_xpm_file_to_image(inf->ptr.mlx,
			"images/P.xpm", &inf->pixel, &inf->pixel);
	inf->ptr.i_pl = mlx_xpm_file_to_image(inf->ptr.mlx,
			"images/Pl.xpm", &inf->pixel, &inf->pixel);
	inf->ptr.i_pd = mlx_xpm_file_to_image(inf->ptr.mlx,
			"images/Pd.xpm", &inf->pixel, &inf->pixel);
	inf->ptr.i_pu = mlx_xpm_file_to_image(inf->ptr.mlx,
			"images/Pu.xpm", &inf->pixel, &inf->pixel);
	inf->ptr.i_pud = mlx_xpm_file_to_image(inf->ptr.mlx,
			"images/Pud.xpm", &inf->pixel, &inf->pixel);
	inf->ptr.i_pul = mlx_xpm_file_to_image(inf->ptr.mlx,
			"images/Plu.xpm", &inf->pixel, &inf->pixel);
	inf->ptr.i_psl = mlx_xpm_file_to_image(inf->ptr.mlx,
			"images/Pls.xpm", &inf->pixel, &inf->pixel);
	inf->ptr.i_psd = mlx_xpm_file_to_image(inf->ptr.mlx,
			"images/Pds.xpm", &inf->pixel, &inf->pixel);
}

void	walkying_helper(t_info *inf)
{
	img_render(inf);
	if (inf->plr.a == 1
		&& inf->matrix[(inf->plr.p_y / 64)]
		[((inf->plr.p_x - 1) / 64)] != '1'
		&& inf->matrix[((inf->plr.p_y + 39) / 64)]
		[((inf->plr.p_x - 1) / 64)] != '1')
		inf->plr.p_x--;
	if (inf->plr.w == 1
		&& inf->matrix[((inf->plr.p_y - 1) / 64)]
		[(inf->plr.p_x / 64)] != '1'
		&& inf->matrix[((inf->plr.p_y - 1) / 64)]
		[((inf->plr.p_x + 39) / 64)] != '1')
		inf->plr.p_y--;
	if (inf->plr.s == 1
		&& inf->matrix[((inf->plr.p_y + 40) / 64)]
		[(inf->plr.p_x / 64)] != '1'
		&& inf->matrix[((inf->plr.p_y + 40) / 64)]
		[((inf->plr.p_x + 39) / 64)] != '1')
		inf->plr.p_y++;
	if (inf->plr.d == 1
		&& inf->matrix[(inf->plr.p_y / 64)]
		[((inf->plr.p_x + 40) / 64)] != '1'
		&& inf->matrix[((inf->plr.p_y + 39) / 64)]
		[((inf->plr.p_x + 40) / 64)] != '1')
		inf->plr.p_x++;
}
