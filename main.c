/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:39:35 by igngonza          #+#    #+#             */
/*   Updated: 2025/02/10 19:27:30 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <X11/keysym.h>
#include <stdio.h>
#include <stdlib.h>
#define WINDOW_WIDTH 400
#define WINDOW_HEIGHT 400

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}			t_vars;

int	ON_KEYUP(int keycode, t_vars *data)
{
	if (keycode == XK_Escape)
	{
		printf("The %d key (ESC) has been pressed\n\n", keycode);
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit(1);
	}
	printf("The %d key has been pressed\n\n", keycode);
	return (0);
}

int	main(void)
{
	t_vars data;

	data.mlx = mlx_init();
	if (data.mlx == NULL)
		return (1);

	data.win = mlx_new_window(data.mlx, WINDOW_HEIGHT, WINDOW_WIDTH,
			"Pixel put");
	if (!data.win)
	{
		mlx_destroy_display(data.mlx);
		free(data.mlx);
		return (1);
	}
	mlx_key_hook(data.win, ON_KEYUP, &data);
	mlx_loop(data.mlx);
}