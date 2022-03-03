/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 19:07:48 by minchoi           #+#    #+#             */
/*   Updated: 2022/03/03 16:57:05 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	init_dir(t_data *data)
{
	if (data->p_dir == 'N' || data->p_dir == 'S')
	{
		data->cam->plane_x = -0.66;
		data->cam->plane_y = 0;
		data->cam->dir_x = 0;
		data->cam->dir_y = 1;
		if (data->p_dir == 'N')
		{
			data->cam->dir_y *= -1;
			data->cam->plane_x = 0.66;
		}		
	}
	else if (data->p_dir == 'W' || data->p_dir == 'E')
	{
		data->cam->plane_x = 0;
		data->cam->plane_y = 0.66;
		data->cam->dir_x = 1;
		data->cam->dir_y = 0;
		if (data->p_dir == 'W')
		{
			data->cam->dir_x *= -1;
			data->cam->plane_y = -0.66;
		}
	}
	data->cam->m_speed = 0.05;
	data->cam->r_speed = 0.05;
}

void	load_image(t_data *data, int *texture, char *path, t_img *img)
{
	img->img = mlx_xpm_file_to_image(data->mlx, path, &img->img_width, &img->img_height);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->size_l, &img->endian);
	for (int y = 0; y < img->img_height; y++)
	{
		for (int x = 0; x < img->img_width; x++)
		{
			texture[img->img_width * y + x] = img->data[img->img_width * y + x];
		}
	}
	mlx_destroy_image(data->mlx, img->img);
}

void	load_texture(t_data *data)
{
	t_img	img;

	for (int i=0; i<4; i++)
		load_image(data, data->cam->texture[i], data->xpm_path[i], &img);
}

int	close_game(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}

int	main(int argc, char *argv[])
{
	int		i;
	char	*buf;
	t_data	data;

	if (argc != 2)
		return (print_err(INVALID_ARG));
	parse_cub(&data, argv[1]);
	//Test to load xpm image file
	for (int i=0; i<HEIGHT; i++)
	{
		for (int j=0; j<WIDTH; j++)
		{
			data.cam->buf[i][j] = 0;
		}
	}
	if (!(data.cam->texture = (int **)malloc(sizeof(int *) * 4)))
		return (-1);
	for (int i=0; i<4; i++)
	{
		if (!(data.cam->texture[i] = (int *)malloc(sizeof(int) * (TEXTUREHEIGHT * TEXTUREWIDTH))))
			return (-1);
	}
	for (int i=0; i<4; i++)
	{
		for (int j=0; j<TEXTUREWIDTH*TEXTUREHEIGHT; j++)
		{
			data.cam->texture[i][j] = 0;
		}
	}
	data.mlx = mlx_init();
	load_texture(&data);
	init_dir(&data);
	printf("(dirx %f, diry %f), (posx %f, posy %f)\n", data.cam->dir_x, data.cam->dir_y, data.cam->pos_x, data.cam->pos_y);
	init_mlx(&data);
	return (0);
}
