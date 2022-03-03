/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 20:03:47 by minchoi           #+#    #+#             */
/*   Updated: 2022/03/02 21:50:42 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "macro.h"

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}	t_mlx;

typedef struct s_img
{
	void	*img;
	int		*data;

	int		size_l;
	int		bpp;
	int		endian;
	int		img_width;
	int		img_height;
}	t_img;


typedef struct s_lay
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	m_speed;
	double	r_speed;

	double	camera_x;
	double	raydir_x;
	double	raydir_y;
	int		map_x;
	int		map_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deldist_x;
	double	deldist_y;
	double	wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;

	int		**texture;
	int		buf[HEIGHT][WIDTH];
	t_img	img;
}	t_lay;

typedef struct s_data {
	char	*xpm_path[4];
	int		floor;
	int		ceiling;
	int		flag;

	char	p_dir;
	int		m_row;
	char	**map;
	t_mlx	mlx_info;
	t_lay	*lay_info;
}				t_data;

/*
** ==================
** utils
** ==================
*/
int		print_err(int err_no);
char	*get_next_line(int fd);
void	init_data(t_data *data);
void	init_mlx(t_data *data);
char	**ft_split_set(char *s, char *charset);
void	free_all(int fd, char *line, t_data *data);
double	ft_fabs(double n);

/*
** ==================
** parse
** ==================
*/
void	parse_cub(t_data *data, char *file_path);
int		parse_type(char *line, t_data *data);
int		parse_map(t_data *data, char *file_path);
int		check_map(t_data *data);
int		check_type(char *line);
int		check_color(char **split);
int		check_xpm(char **split);
int		is_player(t_data *data, int i, int j);

/*
** ==================
** laycasting
** ==================
*/
int		lay_loop(t_data *data);

/*
** ==================
** key
** ==================
*/
int		key_main(int key, t_data *data);
void	key_w(t_lay *info, char **map);
void	key_a(t_lay *info, char **map);
void	key_s(t_lay *info, char **map);
void	key_d(t_lay *info, char **map);
void	key_ar_l(t_lay *info);
void	key_ar_r(t_lay *info);

#endif