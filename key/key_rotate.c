/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minchoi <minchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 01:19:36 by minchoi           #+#    #+#             */
/*   Updated: 2022/03/02 01:43:59 by minchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	key_ar_l(t_lay *info)
{
	double	old_dir_y;
	double	old_plane_y;
	double	rotate;

	rotate = info->r_speed;
	old_dir_y = info->dir_y;
	info->dir_y = info->dir_y * cos(rotate) - info->dir_x * sin(rotate);
	info->dir_x = old_dir_y * sin(rotate) + info->dir_x * cos(rotate);
	old_plane_y = info->plane_y;
	info->plane_y = info->plane_y * cos(rotate) - info->plane_x * sin(rotate);
	info->plane_x = old_plane_y * sin(rotate) + info->plane_x * cos(rotate);
}

void	key_ar_r(t_lay *info)
{
	double	old_dir_y;
	double	old_plane_y;
	double	rotate;

	rotate = info->r_speed;
	old_dir_y = info->dir_y;
	info->dir_y = info->dir_y * cos(-rotate) - info->dir_x * sin(-rotate);
	info->dir_x = old_dir_y * sin(-rotate) + info->dir_x * cos(-rotate);
	old_plane_y = info->plane_y;
	info->plane_y = info->plane_y * cos(-rotate) - info->plane_x * sin(-rotate);
	info->plane_x = old_plane_y * sin(-rotate) + info->plane_x * cos(-rotate);
}
