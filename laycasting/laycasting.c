/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   laycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minchoi <minchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 22:14:10 by gkim              #+#    #+#             */
/*   Updated: 2022/03/03 16:19:11 by minchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	lay_loop(t_data *data)
{
	//경현아 여기다가 천장 바닥 색 넣는 함수 넣으면 될거같아.
	draw_wall(data);
	buf_to_img(data);
	mlx_put_image_to_window(data->mlx, data->win, data->cam->img.img, 0, 0);
}
