/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minchoi <minchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 13:45:53 by minchoi           #+#    #+#             */
/*   Updated: 2022/03/01 16:36:45 by minchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_all(int fd, char *line, t_data *data)
{
	int	i;

	if (fd != 0)
		close(fd);
	if (line != NULL)
		free(line);
	i = -1;
	while (data->xpm_path[++i])
		free(data->xpm_path[i]);
	if (data->map != NULL)
	{
		i = -1;
		while (data->map[++i])
			free(data->map[i]);
		free(data->map);
	}
	exit(1);
}
