/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_cpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandrad <miandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:45:28 by miandrad          #+#    #+#             */
/*   Updated: 2023/01/20 14:10:30 by miandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../So_long.h"

char	**map_cpy(int fd, t_info *inf, char *path)
{
	char	*temp;

	temp = get_next_line(fd);
	while (temp)
	{
		free(temp);
		temp = get_next_line(fd);
		inf->map.width++;
	}
	close(fd);
	inf->matrix = malloc(sizeof(char *) * (inf->map.width + 1));
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

void	free_map(t_info *inf)
{
	int	i;

	i = 0;
	while (inf->matrix[i])
	{
		free(inf->matrix[i]);
		i++;
	}
	get_next_line(-1);
	free(inf->matrix[i]);
	free(inf->matrix);
	exit(0);
}
