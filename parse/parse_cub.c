/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minchoi <minchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:39:57 by minchoi           #+#    #+#             */
/*   Updated: 2022/03/08 15:00:45 by minchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	parse(char *line, t_data *data)
{
	int	type;

	type = check_type(line);
	if (type == 0)
		return (0);
	else if (type == 1)
		return (parse_type(line, data));
	else if (type == 2)
	{
		if (data->flag < 6)
			return (print_err(NOENOUGH_ELEMENT));
		data->m_row++;
	}
	else
		return (print_err(INVALID_ELEMENT));
	return (0);
}

int	parse_cub(t_data *data, char *file_path)
{
	int		fd;
	char	*line;

	if (check_extension(file_path))
		return (print_err(INVALID_FILE));
	init_data(data);
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (print_err(OPEN_ERR));
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (parse(line, data))
			free_all(fd, line, data);
		free(line);
	}
	close(fd);
	parse_map(data, file_path);
	if (check_map(data))
		return (1);
	return (0);
}
