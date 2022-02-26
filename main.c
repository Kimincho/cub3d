/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minchoi <minchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 19:07:48 by minchoi           #+#    #+#             */
/*   Updated: 2022/02/26 20:12:13 by minchoi          ###   ########.fr       */
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

	printf("%s\n", data.xpm_path[NO]);
	printf("%s\n", data.xpm_path[SO]);
	printf("%s\n", data.xpm_path[WE]);
	printf("%s\n", data.xpm_path[EA]);
	printf("%d\n", data.floor);
	printf("%d\n", data.ceiling);
	i = -1;
	while (data.map[++i])
		printf("%s\n", data.map[i]);
	printf("player camera dir : %c\n", data.p_dir);
	printf("player loc y = %d, x = %d\n", data.p_loc_row, data.p_loc_col);
	return (0);
}
