/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minchoi <minchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 20:03:47 by minchoi           #+#    #+#             */
/*   Updated: 2022/02/26 15:23:49 by minchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "macro.h"

typedef struct s_data {
	char	*no_xpm;
	char	*so_xpm;
	char	*we_xpm;
	char	*ea_xpm;
	int		floor;
	int		ceiling;
	int		flag;

	char	p_dir;
	int		p_loc_col;
	int		p_loc_row;
	int		m_row;
	char	**map;
}				t_data;

/*
** ==================
** utils
** ==================
*/
int		print_err(int err_no);
char	*get_next_line(int fd);
void	init_data(t_data *data);
char	**ft_split_set(char *s, char *charset);
void	free_all(int fd, char *line, t_data *data);

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

#endif