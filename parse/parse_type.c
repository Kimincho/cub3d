/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minchoi <minchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:06:57 by minchoi           #+#    #+#             */
/*   Updated: 2022/02/24 21:57:58 by minchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
** put_floor() : 시프트 연산자 이용해서 바닥 color 넣기
** put_ceiling() : 마찬가지로, 천장 color 넣기
*/
void	put_floor(char **split, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (split[++i])
	{
		data->floor = data->floor << 8;
		ft_atoi(split[i], &j);
		data->floor += j;
	}
}

void	put_ceiling(char **split, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (split[++i])
	{
		data->ceiling = data->ceiling << 8;
		ft_atoi(split[i], &j);
		data->ceiling += j;
	}
}

/*
** check_xpm() 로 xpm element 가 올바른 지 체크
** 올바르면 동,서,남,북 식별자 별로 값 저장
** split[1] = NULL; //나중에 free 할 때 해제가 되지 않도록 하기 위함
*/
void	parse_xpm(char **split, t_data *data)
{
	if (check_xpm(split))
	{
		printf("1\n");
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

/*
** check_color() 로 .cub 파일에 color element 가 올바른 지 체크
*/
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

/*
** 공백(isspace) + ',' 문자 set 을 구분 문자로 line 을 split
** 식별자가 'F' 또는 'C' 일 경우 -> parse_color() 호출
** 식별자가 그 외에 경우 -> parse_xpm() 호출
*/
void	parse_type(char *line, t_data *data)
{
	char	**split;

	split = ft_split_set(line, " \t\n\v\f\r,");
	if (!ft_strcmp(split[0], "F") || !ft_strcmp(split[0], "C"))
		parse_color(split, data);
	else
		parse_xpm(split, data);
	data->flag++;
}
