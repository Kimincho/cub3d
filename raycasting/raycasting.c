/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 22:14:10 by gkim              #+#    #+#             */
/*   Updated: 2022/03/03 17:11:41 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ray_loop(t_data *data)
{
	draw_floor_ceil(data, data->cam);
	draw_wall(data);
	buf_to_img(data);
	mlx_put_image_to_window(data->mlx, data->win, data->cam->img.img, 0, 0);
}
