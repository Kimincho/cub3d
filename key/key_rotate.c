/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minchoi <minchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 01:19:36 by minchoi           #+#    #+#             */
/*   Updated: 2022/03/03 16:11:48 by minchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	key_ar_l(t_cam *cam)
{
	double	old_dir_y;
	double	old_plane_y;
	double	rotate;

	rotate = cam->r_speed;
	old_dir_y = cam->dir_y;
	cam->dir_y = cam->dir_y * cos(rotate) - cam->dir_x * sin(rotate);
	cam->dir_x = old_dir_y * sin(rotate) + cam->dir_x * cos(rotate);
	old_plane_y = cam->plane_y;
	cam->plane_y = cam->plane_y * cos(rotate) - cam->plane_x * sin(rotate);
	cam->plane_x = old_plane_y * sin(rotate) + cam->plane_x * cos(rotate);
}

void	key_ar_r(t_cam *cam)
{
	double	old_dir_y;
	double	old_plane_y;
	double	rotate;

	rotate = cam->r_speed;
	old_dir_y = cam->dir_y;
	cam->dir_y = cam->dir_y * cos(-rotate) - cam->dir_x * sin(-rotate);
	cam->dir_x = old_dir_y * sin(-rotate) + cam->dir_x * cos(-rotate);
	old_plane_y = cam->plane_y;
	cam->plane_y = cam->plane_y * cos(-rotate) - cam->plane_x * sin(-rotate);
	cam->plane_x = old_plane_y * sin(-rotate) + cam->plane_x * cos(-rotate);
}
