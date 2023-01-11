/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_cpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandrad <miandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:45:28 by miandrad          #+#    #+#             */
/*   Updated: 2023/01/11 19:07:43 by miandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../So_long.h"

char	**map_cpy(int fd, t_info *inf, char *path)
{
	while (get_next_line(fd))
		inf->map.width++;
	close(fd);
	inf->matrix = malloc(sizeof(char *) * inf->map.width);
	fd = open(path, O_RDONLY);
	while (inf->map.width > 0)
	{
		inf->matrix[inf->map.height] = get_next_line(fd);
		inf->map.height++;
		inf->map.width--;
	}
	inf->matrix[inf->map.height] = 0;
	inf->map.width = ft_strlen_gnl(inf->matrix[0], 1);
	return (inf->matrix);
}
