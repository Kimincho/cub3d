/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minchoi <minchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:08:34 by minchoi           #+#    #+#             */
/*   Updated: 2022/03/01 16:37:50 by minchoi          ###   ########.fr       */
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
int	parse_map(t_data *data, char *file_path)
{
	int		fd;
	char	*line;
	int		i;

	data->map = (char **)malloc(sizeof(char *) * (data->m_row + 1));
	if (data->map == NULL)
		return (print_err(ALLOC_ERR));
	fd = open("./map/example.cub", O_RDONLY);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (check_type(line) != 2)
			continue ;
		else
			put_map_line(data, line, &i);
		free(line);
		i++;
	}
	data->map[data->m_row] = NULL;
	close(fd);
	return (0);
}

/*
** map[i][j] 좌표가 올바른 위치에 있는 지 체크
** 그렇지 않다면 return(print_err(INVALID_MAP));
** return (print_err(INVALID_MAP)) 을 하는 경우
** 1. 현재 좌표가 맵의 모서리에 존재하는 경우
** 2. ft_strlen(map[i-1]) or ft_strlen(map[i+1]) 이 j 값보다 작은 경우
** 3. 현재 좌표 상하좌우 값이 하나라도 isspace() or '\0' 인 경우
*/
int	is_vaild(t_data *data, int i, int j)
{
	char	**map;

	map = data->map;
	if (i <= 0 || j <= 0 || i >= data->m_row || j >= ft_strlen(map[i]))
		return (print_err(INVALID_MAP));
	if (ft_strlen(map[i - 1]) < j || ft_strlen(map[i + 1]) < j)
		return (print_err(INVALID_MAP));
	if (ft_isspace(map[i - 1][j]) || ft_isspace(map[i + 1][j])
		|| ft_isspace(map[i][j - 1]) || ft_isspace(map[i][j + 1]))
		return (print_err(INVALID_MAP));
	if (map[i - 1][j] == '\0' || map[i + 1][j] == '\0'
		|| map[i][j - 1] == '\0' || map[i][j + 1] == '\0')
		return (print_err(INVALID_MAP));
	return (0);
}

/*
** map[i][j] 값을 2중 반복문으로 확인
** 0, 1, isspace, NSWE 가 아닌 다른 문자가 있으면 안됨
*/
int	check_map(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (!ft_isspace(data->map[i][j]) && !is_player(data, i, j)
				&& data->map[i][j] != '0' && data->map[i][j] != '1')
				return (print_err(INVALID_MAP));
			if (is_player(data, i, j) || data->map[i][j] == '0')
			{
				if (is_vaild(data, i, j))
					return (1);
			}
		}
	}
	return (0);
}
