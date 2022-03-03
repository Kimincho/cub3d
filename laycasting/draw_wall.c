/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minchoi <minchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 22:49:02 by minchoi           #+#    #+#             */
/*   Updated: 2022/03/03 16:17:02 by minchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	select_texture(t_cam *cam, t_ray *ray, t_tex *tex)
{
	if (ray->side == 0)
	{
		if (ray->raydir_x > 0)
			tex->tex_num = 2;
		else
			tex->tex_num = 3;
		tex->wall_x = cam->pos_y + ray->wall_dist * ray->raydir_y;
	}
	else
	{
		if (ray->raydir_y > 0)
			tex->tex_num = 0;
		else
			tex->tex_num = 1;
		tex->wall_x = cam->pos_x + ray->wall_dist * ray->raydir_x;
	}
	tex->wall_x -= floor(tex->wall_x);
	tex->tex_x = (int)(tex->wall_x * (double)TEXTUREWIDTH);
	if (ray->side == 0 && ray->raydir_x > 0)
		tex->tex_x = TEXTUREWIDTH - tex->tex_x - 1;
	if (ray->side == 1 && ray->raydir_y < 0)
		tex->tex_x = TEXTUREWIDTH - tex->tex_x - 1;
}

void	tex_to_buf(t_cam *cam, t_ray *ray, t_tex *tex, int x)
{
	int	y;
	int	tex_y;
	int	color;

	tex->step = 1.0 * TEXTUREHEIGHT / ray->line_height;
	tex->tex_pos
		= (ray->draw_start - HEIGHT / 2 + ray->line_height / 2) * tex->step;
	y = ray->draw_start - 1;
	while (++y < ray->draw_end)
	{
		tex_y = (int)tex->tex_pos & (TEXTUREHEIGHT - 1);
		tex->tex_pos += tex->step;
		color = cam->texture[tex->tex_num][TEXTUREHEIGHT * tex_y + tex->tex_x];
		if (ray->side == 1)
			color = (color >> 1) & 8355711;
		cam->buf[y][x] = color;
	}
}

void	draw_wall(t_data *data)
{
	int	x;

	x = -1;
	while (++x < WIDTH)
	{
		init_cam(data->cam, data->ray, x);
		calc_side_dist(data->cam, data->ray);
		dda(data);
		calc_line_hieght(data->cam, data->ray);
		select_texture(data->cam, data->ray, data->tex);
		tex_to_buf(data->cam, data->ray, data->tex, x);
	}
}
