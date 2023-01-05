/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_cpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandrad <miandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:45:28 by miandrad          #+#    #+#             */
/*   Updated: 2023/01/05 18:04:50 by miandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../So_long.h"



char	**map_cpy(int fd, t_ptr *inf, char *path)
{
	char	*str;
	char	**map;

	while (get_next_line(fd))
		inf->m_wdt++;
	close(fd);
	map = malloc(sizeof(char *) * inf->m_wdt);
	fd = open(path, O_RDONLY);
	while (inf->m_wdt > 0)
	{
		str = get_next_line(fd);
		map[inf->m_hgt] = str;
		inf->m_hgt++;
		inf->m_wdt--;
	}
	return (map);
}

