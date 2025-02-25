/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:03:04 by igngonza          #+#    #+#             */
/*   Updated: 2025/02/25 16:59:31 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include "../libft/libft.h"
# include "../printf/ft_printf.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define BACKGROUND "./sprites/Background.xpm"
# define WALL "./sprites/Wall.xpm"
# define CHARACTER "./sprites/Character.xpm"
# define CHECKPOINT "./sprites/Checkpoint.xpm"
# define EXIT "./sprites/End.xpm"
# define CROSS 17

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define UP 126
# define LEFT 123
# define DOWN 125
# define RIGHT 124

typedef struct s_player
{
	int				x;
	int				y;
	int				moves;
}					t_player;

typedef struct s_collectables
{
	int				x;
	int				y;
}					t_collectables;

typedef struct s_exit
{
	int				x;
	int				y;
}					t_exit;

typedef struct img
{
	void			*wall;
	void			*floor;
	void			*food;
	void			*exit;
	void			*character;
	int				y;
	int				x;
	void			*mlx;
	void			*wnd;
}					t_img;

typedef struct s_copy
{
	int				exits;
	int				player;
	int				collect;
}					t_copy;

typedef struct s_map
{
	int				height;
	int				wide;
	char			**matrix;
	char			**copy;
	int				exits;
	int				player;
	int				collect;
	t_player		p;
	t_exit			e;
	t_collectables	c;
	t_copy			co;
	t_img			ph;
}					t_map;

void				items_checker(t_map *map);
void				items_counter(t_map *map);
void				side_checker(t_map *map);
void				len_checker(t_map *map);
void				map_checker(t_map *map);
void				things_check(t_map *map);
void				set_map(int fd, t_map *map);
void				set_height(t_map *map, int fd);
void				starting_position_finder(t_map *map);

void				win(void);
int					moves(int key, t_map *map);
void				up(t_map *map);
void				down(t_map *map);
void				right(t_map *map);
void				left(t_map *map);

void				ft_strerror(char *str);
void				ber_check(char *argv);
int					ft_destroy(void);

int					fill(t_map *map);
void				images(t_map *map);
void				choose(t_map *map, int y, int x);

#endif