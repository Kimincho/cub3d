/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minchoi <minchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:18:44 by minchoi           #+#    #+#             */
/*   Updated: 2022/02/24 17:31:05 by minchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_data(t_data *data)
{
	data->no_xpm = NULL;
	data->so_xpm = NULL;
	data->we_xpm = NULL;
	data->ea_xpm = NULL;
	data->floor = 0;
	data->ceiling = 0;
	data->flag = 0;
	data->p_dir = 0;
	data->p_loc_col = 0;
	data->p_loc_row = 0;
	data->m_col = 0;
	data->m_row = 0;
	data->map = NULL;
}
