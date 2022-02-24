/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minchoi <minchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:47:33 by minchoi           #+#    #+#             */
/*   Updated: 2022/02/24 16:56:54 by minchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
	return (0);
}

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
		if (i == 4)
			return (1);
	}
	return (0);
}

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
