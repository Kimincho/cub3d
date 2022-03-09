# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkim <gkim@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/05 20:43:16 by minchoi           #+#    #+#              #
#    Updated: 2022/03/09 13:34:44 by gkim             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit -g3 -fsanitize=address

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
		./raycasting/raycasting.c\
		./raycasting/draw_wall.c\
		./raycasting/draw_util.c\
		./raycasting/draw_bg.c\
		./raycasting/dda.c\
		./key/key_main.c\
		./key/key_move.c\
		./key/key_rotate.c\

OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I ./

$(NAME): $(OBJS)
	@ make bonus -C ./libft/
	@ make -C ./mlx/
	$(CC) $(MLXFLAGS) -I ./ $^ -o $@ ./libft/libft.a

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
