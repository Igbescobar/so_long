/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:56:15 by igngonza          #+#    #+#             */
/*   Updated: 2025/02/25 15:41:00 by igngonza         ###   ########.fr       */
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
				ft_strerror("INVALID MAP.\n");
			x++;
		}
		y++;
	}
}

void	len_checker(t_map *map)
{
	int	i;

	i = 0;
	map->wide = ft_strlen(map->matrix[0]);
	while (i < map->height)
	{
		if (map->wide != (int)ft_strlen(map->matrix[i]))
		{
			ft_strerror("THE MAP HAVE TO BE RECTANGULAR.\n");
		}
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
				ft_strerror("MAP HAVE TO BE CLOSED BY WALLS.\n");
			if (map->matrix[y][map->wide - 1] != '1'
				|| map->matrix[y][0] != '1')
				ft_strerror("MAP HAVE TO BE CLOSED BY WALLS.\n");
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
	while (y < map->height - 1)
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
	if ((map->exits != 1) || (map->player != 1))
		ft_strerror("THERE HAVE TO BE 1 PLAYER AND 1 EXIT.\n");
	if ((map->collect < 1))
		ft_strerror("THERE HAVE TO BE AT LEAST 1 COLLECTABLE.\n");
}
