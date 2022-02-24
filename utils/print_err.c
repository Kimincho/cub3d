/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minchoi <minchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:11:28 by minchoi           #+#    #+#             */
/*   Updated: 2022/02/24 15:59:53 by minchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int print_err(int err_no)
{
	printf("ERROR : ");
	if (err_no == INVALID_ARG)
		printf("Invalid argument");
	else if (err_no == OPEN_ERR)
		printf("Failed to open the file");
	else if (err_no == INVALID_ELEMENT)
		printf("Invalid element in the file");
	// 메모리 해제 함수 호출 필요
	exit(1);
}
