/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minchoi <minchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:47:33 by minchoi           #+#    #+#             */
/*   Updated: 2022/03/02 13:22:31 by minchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
** NO, SO, WE, EA 가 아닌 다른 문자인 경우
** i > 2 : xpm 파일 경로 1개만 element 로 있어야 되는데 그게 아닌 경우
** xpm 파일 경로가 올바른 지 open() 으로 체크
*/
int	check_xpm(char **split)
{
	int	i;

	i = 0;
	if (ft_strcmp(split[0], "NO") && ft_strcmp(split[0], "SO")
		&& ft_strcmp(split[0], "WE") && ft_strcmp(split[0], "EA"))
		return (1);
	while (split[i])
		i++;
	if (i > 2)
		return (1);
	i = open(split[1], O_RDONLY);
	if (i == -1)
		return (1);
	close(i);
	return (0);
}

/*
** ft_atoi() == 1 인 경우 : 숫자로 이루어진 문자가 아닌 경우
** j : ft_atoi() 로 문자열이 정수로 바뀐 값
** i > 3 : r,g,b 3개의 element 만 있어야 하는데, 그보다 많이 있는 경우
*/
int	check_color(char **split)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (split[++i])
	{
		if (ft_atoi(split[i], &j) == -1)
			return (1);
		if (j < 0 || j > 255)
			return (1);
		if (i > 3)
			return (1);
	}
	return (0);
}

/*
** 공백으로만 이루어진 line -> 0
** line 의 첫 문자가 알파벳인 경우(식별자 정보) -> 1
** line 의 첫 문자가 숫자인 경우(map 정보) -> 2
*/
int	check_type(char *line)
{
	int	i;

	i = -1;
	while (++i < ft_strlen(line))
	{
		if (ft_isspace(line[i]))
			continue ;
		if (ft_isalpha(line[i]))
			return (1);
		if (ft_isdigit(line[i]))
			return (2);
	}
	return (0);
}

int	is_player(t_data *data, int i, int j)
{
	char	c;

	c = data->map[i][j];
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
	{
		data->p_dir = c;
		data->lay_info->pos_x = j + 0.5;
		data->lay_info->pos_y = i + 0.5;
		return (1);
	}
	return (0);
}
