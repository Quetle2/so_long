/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   So_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandrad <miandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 12:55:27 by miandrad          #+#    #+#             */
/*   Updated: 2023/01/17 13:55:56 by miandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include "get_next_line_100/get_next_line.h"
# include "minilibx-linux/mlx.h"

typedef struct s_info
{
	char		**matrix;
	struct s_map
	{
		int		height;
		int		width;
		int		food;
		int		end_x;
		int		end_y;
	}map;
	struct s_ptr
	{
		void	*win_ptr;
		void	*mlx;
		void	*i_open;
		void	*i_dead;
		void	*i_floor;
		void	*i_plr;
		void	*i_pl;
		void	*i_pd;
		void	*i_pu;
		void	*i_pul;
		void	*i_pud;
		void	*i_psd;
		void	*i_psl;
		void	*i_wall;
		void	*i_exit;
		void	*i_col;
		void	*i_lake;
	}ptr;
	struct s_plr
	{
		int		w;
		int		a;
		int		s;
		int		d;
		int		x;
		int		y;
		int		p_x;
		int		p_y;
	}plr;
	int			i;
	int			j;
	int			pixel;
}t_info;

int		keydown(int keycode, t_info *plr_m);
int		keyup(int keycode, t_info *plr_m);
int		walkying(t_info *plr_m);
void	gameinit(t_info *game);
int		close_com(t_info *game);

// map cpy and check;
char	**map_cpy(int fd, t_info *map, char *path);
int		wall_check(t_info *inf);
int		check_cpe(t_info *inf);
int		check_path(int i, int j, t_info *inf);

// img display
void	sprite_atribution(t_info *inf);
void	img_to_window(t_info *inf);
void	img_render(t_info *inf);
void	ifs(t_info *inf, int i, int j);

// interactions and animations
void	colect_food(t_info	*inf);
void	animation(t_info *inf);
void	end_check(t_info *info);

#endif
