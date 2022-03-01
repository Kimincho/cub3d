/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 19:07:48 by minchoi           #+#    #+#             */
/*   Updated: 2022/03/01 10:54:10 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	init_dir(t_data *data)
{
	if (data->p_dir == 'N' || data->p_dir == 'S')
	{
		data->lay_info->plane_x = 0.66;
		data->lay_info->plane_y = 0;
		data->lay_info->dir_x = 0;
		data->lay_info->dir_y = 1;
		if (data->p_dir == 'N')
			data->lay_info->dir_y *= -1;
	}
	else if (data->p_dir == 'W' || data->p_dir == 'E')
	{
		data->lay_info->plane_x = 0;
		data->lay_info->plane_y = 0.66;
		data->lay_info->dir_x = 1;
		data->lay_info->dir_y = 0;
		if (data->p_dir == 'W')
			data->lay_info->dir_x *= -1;
	}
	data->lay_info->m_speed = 0.05;
	data->lay_info->r_speed = 0.05;
}

int	main(int argc, char *argv[])
{
	int		i;
	char	*buf;
	t_data	data;

	if (argc != 2)
		return (print_err(INVALID_ARG));
	parse_cub(&data, argv[1]);
	printf("%s\n", data.xpm_path[NO]);
	printf("%s\n", data.xpm_path[SO]);
	printf("%s\n", data.xpm_path[WE]);
	printf("%s\n", data.xpm_path[EA]);
	printf("%d\n", data.floor);
	printf("%d\n", data.ceiling);
	i = -1;
	while (data.map[++i])
		printf("%s\n", data.map[i]);
	printf("player camera dir : %c\n", data.p_dir);
	printf("player loc y = %d, x = %d\n", data.p_loc_row, data.p_loc_col);
	init_dir(&data);
	printf("(dirx %f, diry %f), (posx %f, posy %f)\n", data.lay_info->dir_x, data.lay_info->dir_y, data.lay_info->pos_x, data.lay_info->pos_y);
	init_mlx(&data);
	return (0);
}
