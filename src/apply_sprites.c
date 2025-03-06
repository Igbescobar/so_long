/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_sprites.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:16:56 by igngonza          #+#    #+#             */
/*   Updated: 2025/03/03 18:41:02 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	choose(t_map *map, int y, int x)
{
	if (map->matrix[y][x] == '1')
		mlx_put_image_to_window(map->img_str.mlx, map->img_str.wnd,
			map->img_str.wall, x * map->img_str.x, y * map->img_str.y);
	else if (map->matrix[y][x] == '0')
		mlx_put_image_to_window(map->img_str.mlx, map->img_str.wnd,
			map->img_str.floor, x * map->img_str.x, y * map->img_str.y);
	else if (map->matrix[y][x] == 'P')
	{
		mlx_put_image_to_window(map->img_str.mlx, map->img_str.wnd,
			map->img_str.floor, x * map->img_str.x, y * map->img_str.y);
		mlx_put_image_to_window(map->img_str.mlx, map->img_str.wnd,
			map->img_str.character, x * map->img_str.x, y * map->img_str.y);
	}
	else if (map->matrix[y][x] == 'E')
		mlx_put_image_to_window(map->img_str.mlx, map->img_str.wnd,
			map->img_str.exit, x * map->img_str.x, y * map->img_str.y);
	else if (map->matrix[y][x] == 'C')
	{
		mlx_put_image_to_window(map->img_str.mlx, map->img_str.wnd,
			map->img_str.floor, x * map->img_str.x, y * map->img_str.y);
		mlx_put_image_to_window(map->img_str.mlx, map->img_str.wnd,
			map->img_str.food, x * map->img_str.x, y * map->img_str.y);
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
	int	y;
	int	x;

	x = 64;
	y = 64;
	map->img_str.y = 50;
	map->img_str.x = 50;
	map->img_str.wall = mlx_xpm_file_to_image(map->img_str.mlx, BUSH, &y, &x);
	map->img_str.floor = mlx_xpm_file_to_image(map->img_str.mlx, BACKGROUND, &y,
			&x);
	map->img_str.character = mlx_xpm_file_to_image(map->img_str.mlx, CHARACTER,
			&y, &x);
	map->img_str.food = mlx_xpm_file_to_image(map->img_str.mlx, POKEBALL, &y,
			&x);
	map->img_str.exit = mlx_xpm_file_to_image(map->img_str.mlx, EXIT, &y, &x);
	if (map->img_str.wall == NULL || map->img_str.floor == NULL
		|| map->img_str.character == NULL || map->img_str.food == NULL
		|| map->img_str.exit == NULL)
		ft_strerror("Issue while loading the sprites.\n");
}
