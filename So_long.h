/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   So_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandrad <miandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:18:41 by miandrad          #+#    #+#             */
/*   Updated: 2023/01/20 16:26:30 by miandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include "get_next_line_100/get_next_line.h"
# include "mlx_linux/mlx.h"

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
		void	*win_ptr2;
		void	*mlx;
		void	*mlx2;
		void	*i_open;
		void	*i_dead;
		void	*i_win;
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
	int			end;
	int			pixel;
	int			win_final;
	size_t		steps;
}t_info;

// helpers
void	main_helper(t_info *inf, char **argv);
void	close_com_helper(t_info *inf);
void	sprite_atribution_helper(t_info *inf);
void	walkying_helper(t_info *inf);

// walking
int		keydown(int keycode, t_info *plr_m);
int		keyup(int keycode, t_info *plr_m);
int		walkying(t_info *plr_m);

// initialization and closure
void	gameinit(t_info *game);
int		close_com(t_info *game);
void	close_io(t_info *inf);
int		end_game(t_info *inf);

// map cpy and check;
char	**map_cpy(int fd, t_info *map, char *path);
int		wall_check(t_info *inf);
int		check_cpe(t_info *inf);
int		check_path(int i, int j, t_info *inf);
int		check_path_more(t_info *inf);
void	free_map(t_info *inf);

// img display
void	sprite_atribution(t_info *inf);
void	img_to_window(t_info *inf);
void	img_render(t_info *inf);
void	ifs(t_info *inf, int i, int j);
void	end_screen(t_info inf);

// interactions and animations
void	colect_food(t_info	*inf);
void	animation(t_info *inf);
void	end_check(t_info *inf);
void	display_victory(t_info inf);

#endif
