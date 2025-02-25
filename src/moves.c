/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:01:25 by igngonza          #+#    #+#             */
/*   Updated: 2025/02/25 16:42:02 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	moves(int key, t_map *map)
{
	if (key == W || key == UP)
		up(map);
	else if (key == S || key == DOWN)
		down(map);
	else if (key == A || key == LEFT)
		left(map);
	else if (key == D || key == RIGHT)
		right(map);
	else if (key == ESC)
		exit(0);
	fill(map);
	ft_printf("\033cMoves \n%d\n", map->p.moves);
	return (0);
}

void	up(t_map *map)
{
	starting_position_finder(map);
	if (map->matrix[map->p.y - 1][map->p.x] == '0')
	{
		map->matrix[map->p.y][map->p.x] = '0';
		map->matrix[map->p.y - 1][map->p.x] = 'P';
		map->p.y = map->p.y - 1;
		map->p.moves++;
	}
	else if (map->matrix[map->p.y - 1][map->p.x] == 'C')
	{
		map->matrix[map->p.y][map->p.x] = '0';
		map->matrix[map->p.y - 1][map->p.x] = 'P';
		map->p.y = map->p.y - 1;
		map->p.moves++;
		map->collect--;
	}
	else if (map->matrix[map->p.y - 1][map->p.x] == 'E' && map->collect == 0)
	{
		map->matrix[map->p.y][map->p.x] = '0';
		map->matrix[map->p.y - 1][map->p.x] = 'P';
		map->p.y = map->p.y - 1;
		map->p.moves++;
		win();
	}
}

void	down(t_map *map)
{
	starting_position_finder(map);
	if (map->matrix[map->p.y + 1][map->p.x] == '0')
	{
		map->matrix[map->p.y][map->p.x] = '0';
		map->matrix[map->p.y + 1][map->p.x] = 'P';
		map->p.y = map->p.y + 1;
		map->p.moves++;
	}
	else if (map->matrix[map->p.y + 1][map->p.x] == 'C')
	{
		map->matrix[map->p.y][map->p.x] = '0';
		map->matrix[map->p.y + 1][map->p.x] = 'P';
		map->p.y = map->p.y + 1;
		map->p.moves++;
		map->collect--;
	}
	else if (map->matrix[map->p.y + 1][map->p.x] == 'E' && map->collect == 0)
	{
		map->matrix[map->p.y][map->p.x] = '0';
		map->p.y = map->p.y + 1;
		map->p.moves++;
		win();
	}
}

void	right(t_map *map)
{
	starting_position_finder(map);
	if (map->matrix[map->p.y][map->p.x + 1] == '0')
	{
		map->matrix[map->p.y][map->p.x] = '0';
		map->matrix[map->p.y][map->p.x + 1] = 'P';
		map->p.y = map->p.x + 1;
		map->p.moves++;
	}
	else if (map->matrix[map->p.y][map->p.x + 1] == 'C')
	{
		map->matrix[map->p.y][map->p.x] = '0';
		map->matrix[map->p.y][map->p.x + 1] = 'P';
		map->p.y = map->p.x + 1;
		map->p.moves++;
		map->collect--;
	}
	else if (map->matrix[map->p.y][map->p.x + 1] == 'E' && map->collect == 0)
	{
		map->matrix[map->p.y][map->p.x] = '0';
		map->matrix[map->p.y][map->p.x + 1] = 'P';
		map->p.y = map->p.x + 1;
		map->p.moves++;
		win();
	}
}

void	left(t_map *map)
{
	starting_position_finder(map);
	if (map->matrix[map->p.y][map->p.x - 1] == '0')
	{
		map->matrix[map->p.y][map->p.x] = '0';
		map->matrix[map->p.y][map->p.x - 1] = 'P';
		map->p.y = map->p.x - 1;
		map->p.moves++;
	}
	else if (map->matrix[map->p.y][map->p.x - 1] == 'C')
	{
		map->matrix[map->p.y][map->p.x] = '0';
		map->matrix[map->p.y][map->p.x - 1] = 'P';
		map->p.y = map->p.x - 1;
		map->p.moves++;
		map->collect--;
	}
	else if (map->matrix[map->p.y][map->p.x - 1] == 'E' && map->collect == 0)
	{
		map->matrix[map->p.y][map->p.x] = '0';
		map->matrix[map->p.y][map->p.x - 1] = 'P';
		map->p.y = map->p.x - 1;
		map->p.moves++;
		win();
	}
}