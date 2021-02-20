/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sajeon <sajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 21:50:39 by sajeon            #+#    #+#             */
/*   Updated: 2021/02/20 19:00:14 by sajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_info	init_info(t_info info)
{
	info.zero = 0;
	info.minus = 0;
	info.dot = -1;
	info.star = 0;
	info.width = 0;
	info.type = 0;
	info.char_count = 0;
}

int	flag_parse(const char *input, int i, t_info *info, va_list args)
{
	while (input[i++])
	{
		if (input[i] == '0' && info->width == 0 && info->minus == 0)
			info->zero = 1;
		if (input[i] == '-')
			treat_flag_minus(*info);
		if (input[i] == '.')
			i = treat_flag_dot(input, i, info, args);
		if (input[i] == '*')
			treat_flag_width(*info, args);
		if (is_in_type_list(input[i]))
		{
			info->type = input[i];
			put_by_type(*info, args);
			break;
		}
		if (!ft_isdigit(input[i]) && !is_in_type_list(input[i])
			&& !is_in_flag_list(input[i]))
			break;
	}
	return (i);
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		i;
	t_info	info;

	i = 0;
	va_start(args, input);
	while (input[i++])
	{
		init_info(info);
		if (input[i] == '%' && input[i + 1])
			i = flag_parse(input, ++i, &info, args);
		else
		{
			ft_putchar_fd(input[i], 1);
			info.char_count++;
		}
	}
	va_end(args);
	return (info.char_count);
}
