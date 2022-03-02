/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minchoi <minchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 15:01:53 by minchoi           #+#    #+#             */
/*   Updated: 2022/03/02 13:15:52 by minchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	key_esc(t_data *data)
{
	// free_all(0, NULL, data);
	exit(0);
}

int	key_main(int key, t_data *data)
{
	for (int i=0; i<HEIGHT; i++)
	{
		for (int j=0; j<WIDTH; j++)
		{
			data->lay_info->buf[i][j] = 0;
		}
	}
	if (key == K_W)
		key_w(data->lay_info, data->map);
	if (key == K_A)
		key_a(data->lay_info, data->map);
	if (key == K_S)
		key_s(data->lay_info, data->map);
	if (key == K_D)
		key_d(data->lay_info, data->map);
	if (key == K_AR_L)
		key_ar_l(data->lay_info);
	if (key == K_AR_R)
		key_ar_r(data->lay_info);
	if (key == K_ESC)
		key_esc(data);
	return (0);
}
