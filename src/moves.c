/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:20:22 by igngonza          #+#    #+#             */
/*   Updated: 2025/03/06 15:47:00 by igngonza         ###   ########.fr       */
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
	ft_printf("\033cMoves \n%d\n", map->player_str.moves);
	if (map->game_won)
		win();
	return (0);
}

void	up(t_map *map)
{
	char	next_pos;

	starting_position_finder(map);
	next_pos = map->matrix[map->player_str.y - 1][map->player_str.x];
	if (next_pos == '1')
		return ;
	if (map->matrix[map->player_str.y][map->player_str.x] == 'P'
		&& map->prev_tile == 'E')
		map->matrix[map->player_str.y][map->player_str.x] = 'E';
	else
		map->matrix[map->player_str.y][map->player_str.x] = '0';
	map->prev_tile = next_pos;
	if (next_pos == '0' || next_pos == 'E' || next_pos == 'C')
	{
		map->matrix[map->player_str.y - 1][map->player_str.x] = 'P';
		map->player_str.y--;
		map->player_str.moves++;
		if (next_pos == 'E' && map->collect == 0)
			win();
		else if (next_pos == 'C')
			map->collect--;
	}
}

void	down(t_map *map)
{
	char	next_pos;

	starting_position_finder(map);
	next_pos = map->matrix[map->player_str.y + 1][map->player_str.x];
	if (next_pos == '1')
		return ;
	if (map->matrix[map->player_str.y][map->player_str.x] == 'P'
		&& map->prev_tile == 'E')
		map->matrix[map->player_str.y][map->player_str.x] = 'E';
	else
		map->matrix[map->player_str.y][map->player_str.x] = '0';
	map->prev_tile = next_pos;
	if (next_pos == '0' || next_pos == 'E' || next_pos == 'C')
	{
		map->matrix[map->player_str.y + 1][map->player_str.x] = 'P';
		map->player_str.y++;
		map->player_str.moves++;
		if (next_pos == 'E' && map->collect == 0)
			map->game_won = 1;
		else if (next_pos == 'C')
			map->collect--;
	}
}

void	right(t_map *map)
{
	char	next_pos;

	starting_position_finder(map);
	next_pos = map->matrix[map->player_str.y][map->player_str.x + 1];
	if (next_pos == '1')
		return ;
	if (map->matrix[map->player_str.y][map->player_str.x] == 'P'
		&& map->prev_tile == 'E')
		map->matrix[map->player_str.y][map->player_str.x] = 'E';
	else
		map->matrix[map->player_str.y][map->player_str.x] = '0';
	map->prev_tile = next_pos;
	if (next_pos == '0' || next_pos == 'E' || next_pos == 'C')
	{
		map->matrix[map->player_str.y][map->player_str.x + 1] = 'P';
		map->player_str.x++;
		map->player_str.moves++;
		if (next_pos == 'E' && map->collect == 0)
			map->game_won = 1;
		else if (next_pos == 'C')
			map->collect--;
	}
}

void	left(t_map *map)
{
	char	next_pos;

	starting_position_finder(map);
	next_pos = map->matrix[map->player_str.y][map->player_str.x - 1];
	if (next_pos == '1')
		return ;
	if (map->matrix[map->player_str.y][map->player_str.x] == 'P'
		&& map->prev_tile == 'E')
		map->matrix[map->player_str.y][map->player_str.x] = 'E';
	else
		map->matrix[map->player_str.y][map->player_str.x] = '0';
	map->prev_tile = next_pos;
	if (next_pos == '0' || next_pos == 'E' || next_pos == 'C')
	{
		map->matrix[map->player_str.y][map->player_str.x - 1] = 'P';
		map->player_str.x--;
		map->player_str.moves++;
		if (next_pos == 'E' && map->collect == 0)
			map->game_won = 1;
		else if (next_pos == 'C')
			map->collect--;
	}
}
