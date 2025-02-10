# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: igngonza <igngonza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/10 18:04:35 by igngonza          #+#    #+#              #
#    Updated: 2025/02/10 18:11:28 by igngonza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MLX_PATH = mlx_linux
NAME = so_long
CC = gcc
#CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -L$(MLX_PATH) -lmlx_Linux -L/usr/lib -I$(MLX_PATH) -lXext -lX11 -lm -lz
OBJECTS = main.o 

all: $(NAME)

%.o: %.c
		$(CC) $(CFLAGS) -I/usr/include -I$(MLX_PATH) -O3 -c $< -o $@

$(NAME): $(OBJECTS)
		$(CC) $(OBJECTS) $(MLX_FLAGS) -o $(NAME)

clean:
		@rm -f $(OBJECTS)

fclean: clean
		@rm -f $(NAME)

re: fclean all