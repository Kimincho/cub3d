/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minchoi <minchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:18:44 by minchoi           #+#    #+#             */
/*   Updated: 2022/02/26 20:14:14 by minchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_data(t_data *data)
{
	data->xpm_path[NO] = NULL;
	data->xpm_path[SO] = NULL;
	data->xpm_path[WE]= NULL;
	data->xpm_path[EA] = NULL;
	data->floor = 0;
	data->ceiling = 0;
	data->flag = 0;
	data->p_dir = 0;
	data->p_loc_col = 0;
	data->p_loc_row = 0;
	data->m_row = 0;
	data->map = NULL;
}
