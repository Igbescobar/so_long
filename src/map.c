/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 20:19:01 by igngonza          #+#    #+#             */
/*   Updated: 2025/02/11 20:25:29 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/colors.h"
#include "../inc/map.h"
#include "../libft/libft.h"
#include <stdio.h>

t_err	ft_newmap_error(void)
{
	t_err map_err;

	map_err.inv_borders = 0;
	map_err.inv_char = 0;
	map_err.inv_n_exits = 0;
	map_err.inv_n_collect = 0;
	map_err.inv_rowlen = 0;
	map_err.inv_n_players = 0;
	map_err.inv_n_ghosts = 0;
	return (map_err);
}