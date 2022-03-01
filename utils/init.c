/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:18:44 by minchoi           #+#    #+#             */
/*   Updated: 2022/03/01 02:03:49 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_mlx(t_data *data)
{
	data->mlx_info.mlx = mlx_init();
	data->mlx_info.win = mlx_new_window(data->mlx_info.mlx,
			WIDTH, HEIGHT, "cub3d");
	mlx_loop_hook(data->mlx_info.mlx, &lay_loop, data);
	mlx_loop(data->mlx_info.mlx);
}

void	init_data(t_data *data)
{
	data->xpm_path[NO] = NULL;
	data->xpm_path[SO] = NULL;
	data->xpm_path[WE] = NULL;
	data->xpm_path[EA] = NULL;
	data->floor = 0;
	data->ceiling = 0;
	data->flag = 0;
	data->p_dir = 0;
	data->p_loc_col = 0;
	data->p_loc_row = 0;
	data->m_row = 0;
	data->map = NULL;
	data->lay_info = (t_lay *)malloc(sizeof(t_lay));
}
