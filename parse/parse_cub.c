/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minchoi <minchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:39:57 by minchoi           #+#    #+#             */
/*   Updated: 2022/02/24 16:51:49 by minchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	parse_xpm(char **split, t_data *data)
{
	if (check_xpm(split))
	{
		ft_free(split);
		print_err(INVALID_ELEMENT);
	}
	if (!ft_strcmp(split[0], "NO"))
		data->no_xpm = split[1];
	else if (!ft_strcmp(split[0], "SO"))
		data->so_xpm = split[1];
	else if (!ft_strcmp(split[0], "WE"))
		data->we_xpm = split[1];
	else if (!ft_strcmp(split[0], "EA"))
		data->ea_xpm = split[1];
	split[1] = NULL;
}

void	parse_color(char **split, t_data *data)
{
	int	i;

	i = 0;
	if (check_color(split))
	{
		ft_free(split);
		print_err(INVALID_ELEMENT);
	}
	if (!ft_strcmp(split[0], "F"))
		put_floor(split, data);
	else
		put_ceiling(split, data);
}

void	parse_type(char *line, t_data *data)
{
	char	**split;

	if (check_type(line) == 0)
		return ;
	if (check_type(line) == 2)
	{
		//map 정보 입력
		return ;
	}
	split = ft_split_set(line, " \t\n\v\f\r,");
	if (!ft_strcmp(split[0], "F") || !ft_strcmp(split[0], "C"))
		parse_color(split, data);
	else
		parse_xpm(split, data);
}

void	parse(char *line, t_data *data)
{
	//line 이 숫자로 시작하는지 문자로 시작하는지 체크
	//숫자로 시작 -> map 정보, 문자로 시작하면 -> 식별자 정보
	//map 정보가 적힌 line 인데 flag 가 아직 0 이면 식별자 정보가 전부 들어온 것이 아니므로, 에러처리
	int	type;

	type = check_type(line);
	if (type == 2)
	// map 정보가 들어오기 시작
	{
		return ;
	}
	parse_type(line, data);
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
		// printf("%s", line);
		free(line);
	}
	close(fd);
}
