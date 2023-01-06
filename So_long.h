/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   So_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandrad <miandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 12:55:27 by miandrad          #+#    #+#             */
/*   Updated: 2023/01/06 17:00:59 by miandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include "get_next_line_100/get_next_line.h"
# include "/nfs/homes/miandrad/Desktop/so_long/minilibx-linux/mlx.h"

typedef struct s_info
{
	struct s_map
	{
		int		height;
		int		width;
		int		food;
	}map;
	struct s_ptr
	{
		void	*win_ptr;
		void	*mlx_ptr;
	}ptr;
	struct s_plr
	{
		int		w;
		int		a;
		int		s;
		int		d;
	}plr;
	int	index;
}t_info;

int		keydown(int keycode, t_info *plr_m);
int		keyup(int keycode, t_info *plr_m);
int		walkying(t_info *plr_m);
void	gameinit(t_info *game);
int		close_com(t_info *game);

// map cpy and check;
char	**map_cpy(int fd, t_info *map, char *path);
int		wall_check(char **map, t_info *inf);
int		check_cpe(char **map, t_info *inf);

#endif