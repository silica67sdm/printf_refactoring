/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sajeon <sajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 21:01:41 by sajeon            #+#    #+#             */
/*   Updated: 2021/02/26 22:33:00 by sajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_string(char *str, t_info *info)
{
	int d_len;
	int s_len;
	int prec;
	int i;

	if (str == NULL)
		str = "(null)";
	s_len = (int)ft_strlen(str);
	d_len = info->dot < 0 ? s_len : info->dot;
	prec = s_len >= d_len ? d_len : s_len;
	i = 0;
	if (info->minus == 1)
		while (i < prec)
		{
			put_char_count(str[i], info);
			i++;
		}
	cal_width(info, info->width, prec, info->zero);
	if (info->minus == 0)
		while (i < prec)
		{
			put_char_count(str[i], info);
			i++;
		}
}
