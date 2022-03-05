/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minchoi <minchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 15:01:53 by minchoi           #+#    #+#             */
/*   Updated: 2022/03/05 20:14:00 by minchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	close_game(t_data *data)
{
	free_all(0, NULL, data);
	mlx_destroy_image(data->mlx, data->cam->img.img);
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}

void	key_esc(t_data *data)
{
	close_game(data);
}

int	key_main(int key, t_data *data)
{
	if (key == K_W)
		key_w(data->cam, data->map);
	if (key == K_A)
		key_a(data->cam, data->map);
	if (key == K_S)
		key_s(data->cam, data->map);
	if (key == K_D)
		key_d(data->cam, data->map);
	if (key == K_AR_L)
		key_ar_l(data->cam);
	if (key == K_AR_R)
		key_ar_r(data->cam);
	if (key == K_ESC)
		key_esc(data);
	return (0);
}
