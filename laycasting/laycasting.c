/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   laycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 22:14:10 by gkim              #+#    #+#             */
/*   Updated: 2022/03/01 11:12:51 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_calc(t_data *data, int x)
{
	t_lay	*info;

	info = data->lay_info;
	info->camera_x = 2 * x / (double)WIDTH - 1;
	info->raydir_x = info->dir_x + info->plane_x * info->camera_x;
	info->raydir_y = info->dir_y + info->plane_y * info->camera_x;
	info->map_x = (int)info->pos_x;
	info->map_y = (int)info->pos_y;
	info->deldist_x = ft_fabs(1 / info->raydir_x);
	info->deldist_y = ft_fabs(1 / info->raydir_y);
}

void	calc_side_dist(t_data *data)
{
	t_lay	*info;

	info = data->lay_info;
	info->step_x = 1;
	info->step_y = 1;
	if (info->raydir_x < 0)
	{
		info->step_x *= -1;
		info->sidedist_x = (info->pos_x - info->map_x) * info->deldist_x;
	}
	else
		info->sidedist_x = (info->map_x + 1.0 - info->pos_x) * info->deldist_x;
	if (info->raydir_y < 0)
	{
		info->step_y *= -1;
		info->sidedist_y = (info->pos_y - info->map_y) * info->deldist_y;
	}
	else
		info->sidedist_y = (info->map_y + 1.0 - info->pos_y) * info->deldist_y;
}

void	check_hit(t_data *data)
{
	t_lay	*info;

	info = data->lay_info;
	if (info->sidedist_x < info->sidedist_y)
	{
		info->sidedist_x += info->deldist_x;
		info->map_x += info->step_x;
		info->side = 0;
	}
	else
	{
		info->sidedist_y += info->deldist_y;
		info->map_y += info->step_y;
		info->side = 1;
	}
	if (ft_strlen(data->map[info->map_y]) > info->map_x
		&& data->map[info->map_y][info->map_x] > 0)
	{
		info->hit = 1;
		if (!info->side)
			info->wall_dist = (info->map_x - info->pos_x
					+ (1 - info->step_x) / 2) / info->raydir_x;
		else
			info->wall_dist = (info->map_y - info->pos_y
					+ (1 - info->step_y) / 2) / info->raydir_y;
	}
}

void	ver_line(t_data *data, int x, int y1, int y2)
{
	int	y;
	int	color;

	color = 0xFF0000;
	if (data->lay_info->side)
		color /= 2;
	y = y1;
	while (y <= y2)
	{
		mlx_pixel_put(data->mlx_info.mlx, data->mlx_info.win, x, y, color);
		y++;
	}
}

void	calc(t_data *data)
{
	int		x;
	int		draw_start;
	int		draw_end;
	int		line_height;
	t_lay	*info;

	x = 0;
	info = data->lay_info;
	while (x < WIDTH)
	{
		init_calc(data, x);
		calc_side_dist(data);
		info->hit = 0;
		while (!info->hit)
			check_hit(data);
		line_height = (int)(HEIGHT / info->wall_dist);
		draw_start = -line_height / 2 + HEIGHT / 2;
		if (draw_start < 0)
			draw_start = 0;
		draw_end = line_height / 2 + HEIGHT / 2;
		if (draw_end >= HEIGHT)
			draw_end = HEIGHT - 1;
		ver_line(data, x, draw_start, draw_end);
		x++;
	}
}

void	lay_loop(t_data *data)
{
	calc(data);
}
