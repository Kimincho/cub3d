/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minchoi <minchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:06:57 by minchoi           #+#    #+#             */
/*   Updated: 2022/02/24 17:19:09 by minchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	put_floor(char **split, t_data *data)
{
	int i;
	int j;

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
	int i;
	int j;

	i = 0;
	while (split[++i])
	{
		data->ceiling = data->ceiling << 8;
		ft_atoi(split[i], &j);
		data->ceiling += j;
	}
}

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

	split = ft_split_set(line, " \t\n\v\f\r,");
	if (!ft_strcmp(split[0], "F") || !ft_strcmp(split[0], "C"))
		parse_color(split, data);
	else
		parse_xpm(split, data);
	data->flag++;
}