/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minchoi <minchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 20:03:47 by minchoi           #+#    #+#             */
/*   Updated: 2022/02/24 14:54:35 by minchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <fcntl.h>
# include "./libft/libft.h"
# include "./mlx/mlx.h"

# define INVALID_ARG			0
# define OPEN_ERR				1

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_KEY_EXIT		17

# define KEY_ESC				53
# define KEY_W					13
# define KEY_A					0
# define KEY_S					1
# define KEY_D					2

typedef struct s_param {
	int		x;
	int		y;
	char	str[3];
}				t_param;

typedef struct s_data {
	char	*no_xpm;
	char	*so_xpm;
	char	*ea_xpm;
	char	*we_xpm;
	int		floor;
	int		ceiling;
	int		flag;

	char	p_dir;
	int		p_loc_col;
	int		p_loc_row;
	int		m_col;
	int		m_row;
	char	**map;
}				t_data;

typedef struct s_info {
	void	*mlx_ptr;
	void	*win_ptr;
}				t_info;

typedef struct s_img {
	void	*img_ptr;
	int		*data;
	int		width;
	int		height;

	int		size_l;
	int		bpp;
	int		endian;
}				t_img;

/*
** ==================
** utils
** ==================
*/
int		print_err(int err_no);
char	*get_next_line(int fd);
void	init_data(t_data *data);

/*
** ==================
** parse
** ==================
*/
void	parse_cub(t_data *data, char *file_path);
int		check_type(char *line);

#endif