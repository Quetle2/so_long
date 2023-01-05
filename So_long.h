/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   So_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandrad <miandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 12:55:27 by miandrad          #+#    #+#             */
/*   Updated: 2023/01/04 18:49:39 by miandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include "get_next_line_100/get_next_line.h"
# include "/nfs/homes/miandrad/Desktop/so_long/minilibx-linux/mlx.h"

typedef struct s_ptr
{
	int		m_hgt;
	int		m_wdt;
	void	*win_ptr;
	void	*mlx_ptr;
	int		w;
	int		a;
	int		s;
	int		d;
}t_ptr;

int		keydown(int keycode, t_ptr *plr_m);
int		keyup(int keycode, t_ptr *plr_m);
int		walkying(t_ptr *plr_m);
void	gameinit(t_ptr *game);

char	**map_cpy(int fd, t_ptr *map);

#endif