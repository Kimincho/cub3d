/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minchoi <minchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 19:07:48 by minchoi           #+#    #+#             */
/*   Updated: 2022/02/24 17:39:51 by minchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

int	main(int argc, char *argv[])
{
	int		i;
	char	*buf;
	t_data	data;

	if (argc != 2)
		return (print_err(INVALID_ARG));
	parse_cub(&data, argv[1]);

	printf("%s\n", data.no_xpm);
	printf("%s\n", data.so_xpm);
	printf("%s\n", data.we_xpm);
	printf("%s\n", data.ea_xpm);
	printf("%d\n", data.floor);
	printf("%d\n", data.ceiling);
	i = -1;
	while (data.map[++i])
		printf("%s\n", data.map[i]);
	return (0);
}
