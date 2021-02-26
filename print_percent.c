/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sajeon <sajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 22:30:24 by sajeon            #+#    #+#             */
/*   Updated: 2021/02/26 22:30:29 by sajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	when_zero(t_info *info)
{
	if (info->minus == 0 && info->zero == 0)
		cal_width(info, info->width, 1, 0);
	if (info->minus == 0 && info->zero == 1)
		cal_width(info, info->width, 1, 1);
	put_char_count('%', info);
	if (info->minus == 1)
		cal_width(info, info->width, 1, 0);
}

void		print_percent(t_info *info)
{
	if (info->dot == 0)
		return (when_zero(info));
	if (info->minus == 1)
	{
		put_char_count('%', info);
		info->zero = 0;
	}
	cal_width(info, info->width, 1, info->zero);
	if (info->minus == 0)
		put_char_count('%', info);
}
