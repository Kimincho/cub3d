CC = gcc
# -Wall -Wextra -Werror 
CFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit -g3 -fsanitize=address

NAME = cub3d

SRCS =	main.c\
		./utils/get_next_line.c\
		./utils/print_err.c\
		./utils/init.c\
		./utils/ft_split_set.c\
		./utils/free.c\
		./parse/parse_cub.c\
		./parse/parse_type.c\
		./parse/parse_map.c\
		./parse/parse_utils.c\
		./laycasting/laycasting.c\
		./laycasting/draw_wall.c\
		./laycasting/draw_util.c\
		./laycasting/dda.c\
		./key/key_main.c\
		./key/key_move.c\
		./key/key_rotate.c\

OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I ./

$(NAME): $(OBJS)
	@ make bonus -C ./libft/
	@ make -C ./mlx/
	$(CC) $(CFLAGS) -I ./ $^ -o $@ ./libft/libft.a

all: $(NAME)

clean:
	rm -rf $(OBJS)
	@ make clean -C ./libft
	@ make clean -C ./mlx

fclean: clean
	rm -rf $(NAME)
	@ make fclean -C ./libft
	@ make clean -C ./mlx

re: fclean all
