/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:21:29 by igngonza          #+#    #+#             */
/*   Updated: 2025/03/03 18:42:34 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_map *map, int y, int x)
{
	map->copy[y][x] = 'P';
	if (map->copy[y - 1][x] == 'E' || map->copy[y - 1][x] == 'C' || map->copy[y
		- 1][x] == '0')
		flood_fill(map, y - 1, x);
	if (map->copy[y + 1][x] == 'E' || map->copy[y + 1][x] == 'C' || map->copy[y
		+ 1][x] == '0')
		flood_fill(map, y + 1, x);
	if (map->copy[y][x - 1] == 'E' || map->copy[y][x - 1] == 'C'
		|| map->copy[y][x - 1] == '0')
		flood_fill(map, y, x - 1);
	if (map->copy[y][x + 1] == 'E' || map->copy[y][x + 1] == 'C'
		|| map->copy[y][x + 1] == '0')
		flood_fill(map, y, x + 1);
}

void	flood_fill_checker(t_map *map)
{
	starting_position_finder(map);
	flood_fill(map, map->player_str.y, map->player_str.x);
	ichecker_copy(map);
	if (map->copy_str.collect != 0 || map->copy_str.exits != 0)
		ft_strerror("Not all items are reachable by the character.\n");
}

void	ichecker_copy(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height - 1)
	{
		x = 0;
		while (x < map->wide)
		{
			if (map->copy[y][x] == 'P')
				map->copy_str.player++;
			if (map->copy[y][x] == 'C')
				map->copy_str.collect++;
			if (map->copy[y][x] == 'E')
				map->copy_str.exits++;
			x++;
		}
		y++;
	}
}

void	things_check(t_map *map)
{
	map_checker(map);
	len_checker(map);
	side_checker(map);
	items_checker(map);
	starting_position_finder(map);
	flood_fill_checker(map);
}

void	ber_check(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 4 || ft_strncmp(filename + len - 4, ".ber", 4) != 0)
		ft_strerror("Only .ber format is allowed.\n");
}
