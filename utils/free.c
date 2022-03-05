/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minchoi <minchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 13:45:53 by minchoi           #+#    #+#             */
/*   Updated: 2022/03/05 20:38:53 by minchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_data(t_data *data)
{
	int	i;

	i = -1;
	if (data->cam->texture != NULL)
	{
		while (++i < 4)
			if (data->cam->texture[i])
				free(data->cam->texture[i]);
		free(data->cam->texture);
	}
	if (data->cam)
		free(data->cam);
	if (data->ray)
		free(data->ray);
	if (data->tex)
		free(data->tex);
}

void	free_all(int fd, char *line, t_data *data)
{
	int	i;

	if (fd != 0)
		close(fd);
	if (line != NULL)
		free(line);
	i = -1;
	while (++i < 4)
		if (data->xpm_path[i])
			free(data->xpm_path[i]);
	if (data->map != NULL)
	{
		i = -1;
		while (data->map[++i])
			free(data->map[i]);
		free(data->map);
	}
	free_data(data);
	exit(1);
}
