/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minchoi <minchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:18:44 by minchoi           #+#    #+#             */
/*   Updated: 2022/02/24 14:33:52 by minchoi          ###   ########.fr       */
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
}
