/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:36:06 by igngonza          #+#    #+#             */
/*   Updated: 2025/02/25 15:22:04 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	set_height(t_map *map, int fd)
{
	char	*line;
	int		i;

	i = 1;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	map->height = i - 1;
	free(line);
	close(fd);
}

void	set_map(int fd, t_map *map)
{
	int i;
	char *file;
	char *line;

	i = 0;
	line = get_next_line(fd);
	file = ft_calloc(1, 1);
	while (line)
	{
		file = ft_strjoin(file, line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	map->matrix = ft_split(file, '\n');
	map->copy = ft_split(file, '\n');
	free(file);
	close(fd);
}