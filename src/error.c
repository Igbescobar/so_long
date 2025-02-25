/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:18:59 by igngonza          #+#    #+#             */
/*   Updated: 2025/02/25 16:15:32 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_strerror(char *str)
{
	write(2, str, ft_strlen(str));
	exit(1);
}

int	ft_destroy(void)
{
	exit(0);
	return (0);
}