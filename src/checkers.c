/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:21:29 by igngonza          #+#    #+#             */
/*   Updated: 2025/02/25 15:19:15 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	things_check(t_map *map)
{
	map_checker(map);
	len_checker(map);
	side_checker(map);
	items_checker(map);
	starting_position_finder(map);
	// last_check(map);
}

void	ber_check(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 4 || ft_strncmp(filename + len - 4, ".ber", 4) != 0)
		ft_strerror("INVALID MAP FORMAT, ONLY .BER IS VALID.\n");
}
