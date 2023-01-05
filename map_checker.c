/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandrad <miandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:22:05 by miandrad          #+#    #+#             */
/*   Updated: 2023/01/05 12:10:42 by miandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_long.h"

int	wall_check(char **map, t_ptr *inf)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen_gnl(map[0], 1) - 1;
	while (i <= j)
	{
		if (map[0][i] != '1' || map[inf->m_hgt - 1][i] != '1')
			return (0);
		i++;
	}
	i = 1;
	while (map[i])
	{
		if ((ft_strlen_gnl(map[i], 1) - 1) != j)
			return (0);
		if (map[i][0] != '1' || map[i][j] != '1')
			return (0);
		i++;
	}
	return (1);
}

char	**map_cpy(int fd, t_ptr *inf)
{
	char	*str;
	char	**map;

	while (get_next_line(fd))
		inf->m_wdt++;
	close(fd);
	map = malloc(sizeof(char *) * inf->m_wdt);
	fd = open("map.ber", O_RDONLY);
	while (inf->m_wdt > 0)
	{
		str = get_next_line(fd);
		map[inf->m_hgt] = str;
		inf->m_hgt++;
		inf->m_wdt--;
	}
	return (map);
}

int	main(int argc, char **argv)
{
	t_ptr	*inf;
	char	**map;
	int		i;
	int		fd;

	i = 0;
	inf = malloc(sizeof(t_ptr));
	inf->m_hgt = 0;
	inf->m_wdt = 0;
	fd = open("map.ber", O_RDONLY);
	map = map_cpy(fd, inf);
	while (map[i])
	{
		printf("%s", map[i]);
		i++;
	}
	if (wall_check(map, inf))
		printf("Yey, Deste lhe forte\n");
	return (0);
}
