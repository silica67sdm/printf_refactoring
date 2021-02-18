/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sajeon <sajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 00:06:55 by sajeon            #+#    #+#             */
/*   Updated: 2021/01/03 19:23:49 by sajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	rst;
	int	sign;

	rst = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		rst *= 10;
		rst += (*str - '0');
		str++;
	}
	if (rst > 2147483647)
		return (-1);
	else if (rst < -2147483648)
		return (0);
	return (int)(rst * sign);
}
