/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sajeon <sajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 21:00:29 by sajeon            #+#    #+#             */
/*   Updated: 2021/02/26 22:26:27 by sajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(char k, t_info *info)
{
	if (info->minus == 1)
		put_char_count(k, info);
	cal_width(info, info->width, 1, info->zero);
	if (info->minus == 0)
		put_char_count(k, info);
}
