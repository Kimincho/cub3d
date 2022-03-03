/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:50:29 by gkim              #+#    #+#             */
/*   Updated: 2022/03/03 17:00:56 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_floor_ceil(t_data *data, t_cam *cam)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			cam->buf[y][x] = data->floor;
			cam->buf[HEIGHT - y - 1][x] = data->ceiling;
			x++;
		}
		y++;
	}
}
