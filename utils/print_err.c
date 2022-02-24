/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minchoi <minchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:11:28 by minchoi           #+#    #+#             */
/*   Updated: 2022/02/24 21:51:32 by minchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int print_err(int err_no)
{
	printf("ERROR : ");
	if (err_no == INVALID_ARG)
		printf("Invalid argument\n");
	else if (err_no == OPEN_ERR)
		printf("Failed to open the file\n");
	else if (err_no == INVALID_ELEMENT)
		printf("Invalid element in the file\n");
	else if (err_no == NOENOUGH_ELEMENT)
		printf("Not enough element in the file\n");
	else if (err_no == ALLOC_ERR)
		printf("Allocated error\n");
	// 메모리 해제 함수 호출 필요
	exit(1);
}
