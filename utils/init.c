/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:18:44 by minchoi           #+#    #+#             */
/*   Updated: 2022/03/03 17:12:28 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_mlx(t_data *data)
{
	t_cam	*cam;

	cam = data->cam;
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "cub3d");
	cam->img.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	cam->img.data = (int *)mlx_get_data_addr(cam->img.img,
			&cam->img.bpp, &cam->img.size_l, &cam->img.endian);
	mlx_loop_hook(data->mlx, &ray_loop, data);
	mlx_hook(data->win, X_EVENT_KEY_PRESS, 0, &key_main, data);
	mlx_hook(data->win, X_EVENT_KEY_EXIT, 0, &close_game, data);
	mlx_loop(data->mlx);
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
	data->m_row = 0;
	data->map = NULL;
	data->cam = (t_cam *)malloc(sizeof(t_cam));
	data->ray = (t_ray *)malloc(sizeof(t_ray));
	data->tex = (t_tex *)malloc(sizeof(t_tex));
}
