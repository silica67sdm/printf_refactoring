/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sajeon <sajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 21:05:12 by sajeon            #+#    #+#             */
/*   Updated: 2021/02/25 21:06:20 by sajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_in_type_list(int k)
{
	return ((k == 'c') || (k == 's') || (k == 'p')
			|| (k == 'd') || (k == 'i') || (k == 'u')
			|| (k == 'x') || (k == 'X') || (k == '%'));
}

int		is_in_flag_list(int k)
{
	return ((k == '-') || (k == ' ') || (k == '0')
			|| (k == '.') || (k == '*'));
}

void	cal_width(t_info *info, int len1, int len2, int zero)
{
	while (len1 - len2 > 0)
	{
		if (zero == 1)
			put_char_count('0', info);
		else
			put_char_count(' ', info);
		len1 -= 1;
	}
}

void	put_char_count(int k, t_info *info)
{
	ft_putchar_fd(k, 1);
	info->char_count += 1;
}