# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: igngonza <igngonza@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/10 18:04:35 by igngonza          #+#    #+#              #
#    Updated: 2025/02/11 18:32:41 by igngonza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MLX_PATH = mlx_linux
MLX_DIR = mlx_linux
NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c
OBJS = $(SRCS:.c=.o)

ifeq ($(shell uname), Linux)
    INCLUDES = -I/usr/include -I$(MLX_PATH)
    MLX_FLAGS = -L$(MLX_PATH) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz
else
    INCLUDES = -I/opt/X11/include -I$(MLX_PATH)
    MLX_FLAGS = -L$(MLX_PATH) -lmlx -framework OpenGL -framework AppKit
    X11_FLAGS = -L/usr/X11/lib -lXext -lX11
endif

all: $(MLX_LIB) $(NAME)

%.o: %.c
		$(CC) $(CFLAGS) -I$(MLX_PATH) -c -o $@ $< $(INCLUDES)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(MLX_FLAGS) $(X11_FLAGS) -o $(NAME) $(OBJS)

$(MLX_LIB):
		@make -C $(MLX_DIR)

clean:
		@rm -f $(OBJS)

fclean: clean
		@rm -f $(NAME)

re: fclean all