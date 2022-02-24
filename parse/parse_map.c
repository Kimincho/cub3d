/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minchoi <minchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:08:34 by minchoi           #+#    #+#             */
/*   Updated: 2022/02/24 22:09:54 by minchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
** gnl 로 읽은 line 의 맨 마지막 문자가 '\n' 인 경우와 아닌 경우로 나눔
** 파일의 마지막 문장에만 '\n' 문자가 안 붙기 때문이다
*/
void	put_map_line(t_data *data, char *line, int *i)
{
	if (line[ft_strlen(line)-1] == '\n')
	{
		data->map[*i] = (char *)malloc(sizeof(char) * ft_strlen(line));
		ft_strlcpy(data->map[*i], line, ft_strlen(line));
	}
	else
	{
		data->map[*i] = (char *)malloc(sizeof(char) * (ft_strlen(line) + 1));
		ft_strlcpy(data->map[*i], line, ft_strlen(line) + 1);
	}
}

/*
** gnl 을 이용해서 map 정보를 그대로 저장
** check_type() 이 2 일 때만 map 에 대한 정보
** line 의 맨 마지막에 \n 이 붙어있는 경우와 아닌 경우를 나눠서 malloc
*/
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
			put_map_line(data, line, &i);
		free(line);
		i++;
	}
	data->map[data->m_row] = NULL;
}