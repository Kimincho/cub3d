/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minchoi <minchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:39:19 by minchoi           #+#    #+#             */
/*   Updated: 2022/02/24 16:41:58 by minchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	put_floor(char **split, t_data *data)
{
	int i;
	int j;

	i = 0;
	while (split[++i])
	{
		data->floor = data->floor << 8;
		ft_atoi(split[i], &j);
		data->floor += j;
	}
}

void	put_ceiling(char **split, t_data *data)
{
	int i;
	int j;

	i = 0;
	while (split[++i])
	{
		data->ceiling = data->ceiling << 8;
		ft_atoi(split[i], &j);
		data->ceiling += j;
	}
}