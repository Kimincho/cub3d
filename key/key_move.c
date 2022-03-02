/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minchoi <minchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 01:16:11 by minchoi           #+#    #+#             */
/*   Updated: 2022/03/02 02:52:37 by minchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	key_w(t_lay *info, char **map)
{
	double	move_x;
	double	move_y;

	move_x = info->dir_x * info->m_speed;
	move_y = info->dir_y * info->m_speed;
	if (map[(int)(info->pos_y + move_y)][(int)(info->pos_x)] != '1')
		info->pos_y += move_y;
	if (map[(int)(info->pos_y)][(int)(info->pos_x + move_x)] != '1')
		info->pos_x += move_x;
}

void	key_s(t_lay *info, char **map)
{
	double	move_x;
	double	move_y;

	move_x = info->dir_x * info->m_speed;
	move_y = info->dir_y * info->m_speed;
	if (map[(int)(info->pos_y - move_y)][(int)(info->pos_x)] != '1')
		info->pos_y -= move_y;
	if (map[(int)(info->pos_y)][(int)(info->pos_x - move_x)] != '1')
		info->pos_x -= move_x;
}

void	key_a(t_lay *info, char **map)
{
	double	move_x;
	double	move_y;

	move_x = info->dir_x * info->m_speed;
	move_y = info->dir_y * info->m_speed;
	if (map[(int)(info->pos_y - move_x)][(int)(info->pos_x)] != '1')
		info->pos_y -= move_x;
	if (map[(int)(info->pos_y)][(int)(info->pos_x + move_y)] != '1')
		info->pos_x += move_y;
}

void	key_d(t_lay *info, char **map)
{
	double	move_x;
	double	move_y;

	move_x = info->dir_x * info->m_speed;
	move_y = info->dir_y * info->m_speed;
	if (map[(int)(info->pos_y + move_x)][(int)(info->pos_x)] != '1')
		info->pos_y += move_x;
	if (map[(int)(info->pos_y)][(int)(info->pos_x - move_y)] != '1')
		info->pos_x -= move_y;
}
