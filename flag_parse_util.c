/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_parse_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sajeon <sajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 20:58:20 by sajeon            #+#    #+#             */
/*   Updated: 2021/02/25 20:59:23 by sajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_parse_minus(t_info *info)
{
	info->minus = 1;
	if (info->zero)
		info->zero = 0;
}

int		flag_parse_dot(const char *input, int i, t_info *info, va_list args_pt)
{
	if (input[i] == '*')
	{
		info->dot = va_arg(args_pt, int);
		i++;
	}
	else
	{
		info->dot = 0;
		while (ft_isdigit(input[i]))
		{
			info->dot = info->dot * 10 + (input[i] - '0');
			i++;
		}
	}
	i--;
	return (i);
}

void	flag_parse_width(t_info *info, va_list args_pt)
{
	info->width = va_arg(args_pt, int);
	if (info->width < 0)
	{
		info->minus = 1;
		info->width *= -1;
	}
}

int		flag_parse_digit(const char *input, int i, t_info *info)
{
	info->width = 0;
	while (ft_isdigit(input[i]))
	{
		info->width = info->width * 10 + (input[i] - '0');
		i++;
	}
	i--;
	return (i);
}