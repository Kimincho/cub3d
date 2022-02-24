/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minchoi <minchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:39:57 by minchoi           #+#    #+#             */
/*   Updated: 2022/02/24 17:35:01 by minchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	parse(char *line, t_data *data)
{
	//line 이 숫자로 시작하는지 문자로 시작하는지 체크
	//숫자로 시작 -> map 정보, 문자로 시작하면 -> 식별자 정보
	//map 정보가 적힌 line 인데 flag 가 아직 0 이면 식별자 정보가 전부 들어온 것이 아니므로, 에러처리
	int	type;

	type = check_type(line);
	if (type == 0)
		return ;
	else if (type == 1)
		parse_type(line, data);
	else if (type == 2)
	{
		if (data->flag < 6)
			print_err(NOENOUGH_ELEMENT);
		data->m_row++;
	}
}

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
			break;
		parse(line, data);
		free(line);
	}
	close(fd);
	parse_map(data, file_path);
}
