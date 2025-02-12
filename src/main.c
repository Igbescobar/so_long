/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:39:35 by igngonza          #+#    #+#             */
/*   Updated: 2025/02/11 19:19:18 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/check.h"
#include "../inc/game.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	char **map;
	t_lay lay;

	map = check_params(argc, argv, &lay);
	init_game(map, lay);
	return (0);
}