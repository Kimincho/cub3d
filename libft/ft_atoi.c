/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minchoi <minchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 14:43:27 by hynam             #+#    #+#             */
/*   Updated: 2022/02/24 16:17:25 by minchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char *str, int *n)
{
	int		i;
	int		sign;
	long	nbr;

	i = 0;
	sign = 1;
	nbr = 0;
	if ((str[i] == '+' || str[i] == '-') && ft_isdigit(str[i + 1]))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	else if ((str[i] == '+' || str[i] == '-') && str[i + 1] == '\0')
		return (-1);
	while (str[i] && ft_isdigit(str[i]))
		nbr = nbr * 10 + (str[i++] - '0');
	if (i == 0 || (str[i] && !ft_isdigit(str[i])))
		return (-1);
	*n = nbr * sign;
	return (i);
}
