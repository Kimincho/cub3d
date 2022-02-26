/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minchoi <minchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:39:57 by minchoi           #+#    #+#             */
/*   Updated: 2022/02/26 15:36:18 by minchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
** map 을 제외한 정보 파싱 & map 행 수 체크
*/
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
	return (0);
}

/*
** file_path 에 해당하는 파일을 열고 파싱 시작
** parse() 함수에서 map 을 제외한 정보를 파싱하고,
** parse_map() 에서 .cub 파일을 다시 한번 열어서, map 정보 파싱
** check_map() 에서 올바른 맵인지 체크
*/
void	parse_cub(t_data *data, char *file_path)
{
	int		fd;
	char	*line;

	init_data(data);
	fd = open("./map/example.cub", O_RDONLY);
	if (fd == -1)
		print_err(OPEN_ERR);
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
		free_all(0, NULL, data);
}
