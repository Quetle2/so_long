/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_cpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandrad <miandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:45:28 by miandrad          #+#    #+#             */
/*   Updated: 2023/01/06 18:16:44 by miandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../So_long.h"



char	**map_cpy(int fd, t_info *inf, char *path)
{
	char	*str;
	char	**map;

	while (get_next_line(fd))
		inf->map.width++;
	close(fd);
	map = malloc(sizeof(char *) * inf->map.width);
	fd = open(path, O_RDONLY);
	while (inf->map.width > 0)
	{
		map[inf->map.height] = get_next_line(fd);
		inf->map.height++;
		inf->map.width--;
	}
	map[inf->map.height] = 0;
	return (map);
}
