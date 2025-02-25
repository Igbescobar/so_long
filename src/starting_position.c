/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starting_position.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:17:27 by igngonza          #+#    #+#             */
/*   Updated: 2025/02/25 15:17:52 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	starting_position_finder(t_map *map)
{
	int y;
	int x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->wide)
		{
			if (map->matrix[y][x] == 'P')
			{
				map->p.x = x;
				map->p.y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}