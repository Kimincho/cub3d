/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minchoi <minchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:08:34 by minchoi           #+#    #+#             */
/*   Updated: 2022/02/24 17:47:35 by minchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	parse_map(t_data *data, char *file_path)
{
	int		fd;
	char	*line;
	int		i;

	data->map = (char **)malloc(sizeof(char *) * (data->m_row + 1));
	if (data->map == NULL)
		print_err(ALLOC_ERR);
	fd = open("./map/example.cub", O_RDONLY);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		if (check_type(line) != 2)
			continue ;
		else
		{
			data->map[i] = (char *)malloc(sizeof(char) * ft_strlen(line));
			ft_strlcpy(data->map[i], line, ft_strlen(line));
		}
		free(line);
		i++;
	}
	data->map[data->m_row] = NULL;
}