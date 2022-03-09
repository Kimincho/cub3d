/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:11:28 by minchoi           #+#    #+#             */
/*   Updated: 2022/03/09 13:37:29 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	print_err(int err_no)
{
	printf("ERROR : ");
	if (err_no == INVALID_ARG)
		return (printf("Invalid argument\n"));
	else if (err_no == OPEN_ERR)
		return (printf("Failed to open the file\n"));
	else if (err_no == INVALID_ELEMENT)
		return (printf("Invalid element in the file\n"));
	else if (err_no == NOENOUGH_ELEMENT)
		return (printf("Not enough element in the file\n"));
	else if (err_no == ALLOC_ERR)
		return (printf("Allocated error\n"));
	else if (err_no == INVALID_MAP)
		return (printf("Invalid map\n"));
	else if (err_no == INVALID_FILE)
		return (printf("Inavalid file\n"));
	else if (err_no == NONE_PLAYER)
		return (printf("None player\n"));
	else if (err_no == TOO_MANY_PLAYER)
		return (printf("Too many player\n"));
	return (0);
}
