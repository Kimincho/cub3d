CC = gcc
# -Wall -Wextra -Werror 
CFLAGS = -L./mlx -lmlx -framework OpenGL -framework AppKit -g3 -fsanitize=address

NAME = cub3d

SRCS =	main.c\
		./utils/get_next_line.c\
		./utils/print_err.c\
		./utils/init.c\
		./parse/parse_cub.c\
		./parse/parse_utils.c\

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
