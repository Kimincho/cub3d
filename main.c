/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minchoi <minchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 19:07:48 by minchoi           #+#    #+#             */
/*   Updated: 2022/03/05 20:28:15 by minchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

int	init_buf_tex(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < HEIGHT)
	{
		j = -1;
		while (++j < WIDTH)
			data->cam->buf[i][j] = 0;
	}
	data->cam->texture = (int **)malloc(sizeof(int *) * 4);
	if (data->cam->texture == NULL)
		return (print_err(ALLOC_ERR));
	i = -1;
	while (++i < 4)
	{
		data->cam->texture[i] = (int *)malloc(sizeof(int)
				* (TEXTUREHEIGHT * TEXTUREWIDTH));
		if (data->cam->texture[i] == NULL)
			return (print_err(ALLOC_ERR));
		j = -1;
		while (++j < TEXTUREWIDTH * TEXTUREHEIGHT)
			data->cam->texture[i][j] = 0;
	}
	return (0);
}

void	load_image(t_data *data, int *texture, char *path, t_img *img)
{
	int	i;
	int	j;

	img->img = mlx_xpm_file_to_image(data->mlx, path,
			&img->img_width, &img->img_height);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp,
			&img->size_l, &img->endian);
	i = -1;
	while (++i < img->img_height)
	{
		j = -1;
		while (++j < img->img_width)
			texture[img->img_width * i + j] = img->data[img->img_width * i + j];
	}
	mlx_destroy_image(data->mlx, img->img);
}

void	load_texture(t_data *data)
{
	t_img	img;
	int		i;

	i = -1;
	while (++i < 4)
		load_image(data, data->cam->texture[i], data->xpm_path[i], &img);
}

int	main(int argc, char *argv[])
{
	int		i;
	char	*buf;
	t_data	data;

	if (argc != 2)
		return (print_err(INVALID_ARG));
	if (parse_cub(&data, argv[1]))
		free_all(0, NULL, &data);
	if (init_buf_tex(&data))
		free_all(0, NULL, &data);
	data.mlx = mlx_init();
	load_texture(&data);
	init_dir(&data);
	init_mlx(&data);
	return (0);
}
