NAME = so_long

CC = gcc

CFLAGS = -Wall -Werror -Wextra

CFLAGS += -I ./includes

INCLUDES = -I/usr/include -Imlx

FLAGS_MLX = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

PRINT_LIB = printf/libftprintf.a

LIB_FT = libft/libft.a

SRCS_SL = get_next_line.c get_next_line_utils.c starting_position.c map.c map_checker.c error.c main.c checkers.c apply_sprites.c moves.c win.c

SRCS = $(addprefix src/, $(SRCS_SL))

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) mlx/libmlx.a
	@make -C printf
	@make -C libft
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(FLAGS_MLX) $(PRINT_LIB) $(LIB_FT) -o $(NAME)

mlx/libmlx.a:
	@$(MAKE) -C mlx

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@make fclean -C printf
	@make fclean -C libft
	@make clean -C mlx
	rm -f $(OBJS)

fclean:	clean
	@make fclean -C printf
	@make fclean -C libft
	@make clean -C mlx
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re