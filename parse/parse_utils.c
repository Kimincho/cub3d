/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minchoi <minchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:47:33 by minchoi           #+#    #+#             */
/*   Updated: 2022/02/24 14:55:25 by minchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_type(char *line)
{
	int i;

	i = -1;
	while (++i < ft_strlen(line))
	{
		if (ft_isspace(line[i]))
			continue;
		if (ft_isalpha(line[i]))
			return (1);
		if (ft_isdigit(line[i]))
			return (2);
	}
	return (0);
}
