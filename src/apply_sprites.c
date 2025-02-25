/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_sprites.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:16:56 by igngonza          #+#    #+#             */
/*   Updated: 2025/02/25 17:02:45 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	choose(t_map *map, int y, int x)
{
	if (map->matrix[y][x] == '1')
		mlx_put_image_to_window(map->ph.mlx, map->ph.wnd, map->ph.wall, x
			* map->ph.x, y * map->ph.y);
	else if (map->matrix[y][x] == '0')
		mlx_put_image_to_window(map->ph.mlx, map->ph.wnd, map->ph.floor, x
			* map->ph.x, y * map->ph.y);
	else if (map->matrix[y][x] == 'P')
	{
		mlx_put_image_to_window(map->ph.mlx, map->ph.wnd, map->ph.floor, x
			* map->ph.x, y * map->ph.y);
		mlx_put_image_to_window(map->ph.mlx, map->ph.wnd, map->ph.character, x
			* map->ph.x, y * map->ph.y);
	}
	else if (map->matrix[y][x] == 'E')
		mlx_put_image_to_window(map->ph.mlx, map->ph.wnd, map->ph.exit, x
			* map->ph.x, y * map->ph.y);
	else if (map->matrix[y][x] == 'C')
	{
		mlx_put_image_to_window(map->ph.mlx, map->ph.wnd, map->ph.floor, x
			* map->ph.x, y * map->ph.y);
		mlx_put_image_to_window(map->ph.mlx, map->ph.wnd, map->ph.food, x
			* map->ph.x, y * map->ph.y);
	}
}

int	fill(t_map *map)
{
	int	x;
	int	y;

	y = -1;
	images(map);
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->wide)
			choose(map, y, x);
	}
	return (0);
}

void	images(t_map *map)
{
	int y;
	int x;

	x = 64;
	y = 64;
	map->ph.y = 64;
	map->ph.x = 64;
	map->ph.wall = mlx_xpm_file_to_image(map->ph.mlx, BACKGROUND, &y, &x);
	map->ph.floor = mlx_xpm_file_to_image(map->ph.mlx, WALL, &y, &x);
	map->ph.character = mlx_xpm_file_to_image(map->ph.mlx, CHARACTER, &y, &x);
	map->ph.food = mlx_xpm_file_to_image(map->ph.mlx, CHECKPOINT, &y, &x);
	map->ph.exit = mlx_xpm_file_to_image(map->ph.mlx, EXIT, &y, &x);
	if (map->ph.wall == NULL || map->ph.floor == NULL
		|| map->ph.character == NULL || map->ph.food == NULL
		|| map->ph.exit == NULL)
		ft_strerror("UNABLE TO LOAD SPRITES.\n");
}