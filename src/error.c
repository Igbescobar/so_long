/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:18:59 by igngonza          #+#    #+#             */
/*   Updated: 2025/03/06 12:29:37 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_strerror(char *str)
{
	write(1, "Error\n", 6);
	write(1, str, ft_strlen(str));
	exit(1);
}

void	cleanup(t_map *map)
{
	if (map->img_str.wall)
		mlx_destroy_image(map->img_str.mlx, map->img_str.wall);
	if (map->img_str.floor)
		mlx_destroy_image(map->img_str.mlx, map->img_str.floor);
	if (map->img_str.character)
		mlx_destroy_image(map->img_str.mlx, map->img_str.character);
	if (map->img_str.food)
		mlx_destroy_image(map->img_str.mlx, map->img_str.food);
	if (map->img_str.exit)
		mlx_destroy_image(map->img_str.mlx, map->img_str.exit);
	if (map->img_str.wnd)
		mlx_destroy_window(map->img_str.mlx, map->img_str.wnd);
}

int	ft_destroy(void *param)
{
	t_map	*map;

	map = (t_map *)param;
	cleanup(map);
	exit(0);
	return (0);
}
