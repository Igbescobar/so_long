/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:05:35 by igngonza          #+#    #+#             */
/*   Updated: 2025/03/06 12:32:41 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	initialize_map(t_map *map, char *filename)
{
	int	fd1;
	int	fd2;

	fd1 = open(filename, O_RDONLY);
	fd2 = open(filename, O_RDONLY);
	if (fd1 < 0 || fd2 < 0)
		ft_strerror("Issue opening the file\n");
	set_height(map, fd1);
	set_map(fd2, map);
	things_check(map);
	close(fd1);
	close(fd2);
}

static void	setup_game(t_map *map)
{
	map->img_str.mlx = mlx_init();
	map->img_str.wnd = mlx_new_window(map->img_str.mlx, map->wide * 50,
			map->height * 50, "Game");
	fill(map);
	mlx_key_hook(map->img_str.wnd, moves, map);
	mlx_hook(map->img_str.wnd, CLOSE, 0, ft_destroy, map);
	mlx_loop(map->img_str.mlx);
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
		ft_strerror("Wrong number of arguments.\n");
	ber_check(argv[1]);
	ft_memset(&map, 0, sizeof(t_map));
	initialize_map(&map, argv[1]);
	setup_game(&map);
	atexit((void (*)(void))cleanup);
	return (0);
}
