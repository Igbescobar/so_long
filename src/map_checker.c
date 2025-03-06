/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:56:15 by igngonza          #+#    #+#             */
/*   Updated: 2025/03/06 11:24:30 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_checker(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (map->matrix[y])
	{
		x = 0;
		while (map->matrix[y][x])
		{
			if (map->matrix[y][x] != '0' && map->matrix[y][x] != 'E'
				&& map->matrix[y][x] != 'C' && map->matrix[y][x] != '1'
				&& map->matrix[y][x] != 'P')
				ft_strerror("Map does not followed the imposed rules.\n");
			x++;
		}
		y++;
	}
}

void	len_checker(t_map *map)
{
	int	i;

	i = 0;
	if (map->height <= 0)
		ft_strerror("The map height is invalid.\n");
	map->wide = ft_strlen(map->matrix[0]);
	while (i < map->height)
	{
		if (map->matrix[i] == NULL)
			ft_strerror("The map is not rectangular.\n");
		if (map->wide != (int)ft_strlen(map->matrix[i]))
			ft_strerror("The map is not rectangular.\n");
		i++;
	}
}

void	side_checker(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (map->matrix[y])
	{
		while (map->matrix[y][x])
		{
			if (map->matrix[0][x] != '1' || map->matrix[map->height
				- 1][x] != '1')
				ft_strerror("The map has to be enclosed by walls.\n");
			if (map->matrix[y][map->wide - 1] != '1'
				|| map->matrix[y][0] != '1')
				ft_strerror("The map has to be enclosed by walls.\n");
			x++;
		}
		x = 0;
		y++;
	}
}

void	items_counter(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->wide)
		{
			if (map->matrix[y][x] == 'P')
				map->player++;
			if (map->matrix[y][x] == 'C')
				map->collect++;
			if (map->matrix[y][x] == 'E')
				map->exits++;
			x++;
		}
		y++;
	}
}

void	items_checker(t_map *map)
{
	items_counter(map);
	if (map->exits != 1)
		ft_strerror("There can only be one exit.\n");
	if (map->player != 1)
		ft_strerror("There can only be one player.\n");
	if ((map->collect < 1))
		ft_strerror("There has to be at least one collective.\n");
}
