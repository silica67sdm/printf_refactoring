/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sajeon <sajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 21:50:39 by sajeon            #+#    #+#             */
/*   Updated: 2021/02/26 14:22:09 by sajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *input, ...)
{
	va_list	args_pt;
	t_info	info;
	int		i;
	int		sum_count;

	sum_count = 0;
	i = 0;
	va_start(args_pt, input);
	while (input[i])
	{
		init_info(&info);
		if (input[i] == '%' && input[i + 1])
		{
			i = flag_parse(input, ++i, &info, args_pt);
			print_and_cal_input(&info, args_pt, info.type);
		}
		else
			put_char_count(input[i], &info);
		i++;
		sum_count += info.char_count;
	}
	va_end(args_pt);
	return (sum_count);
}

void	init_info(t_info *info)
{
	info->zero = 0;
	info->minus = 0;
	info->dot = -1;
	info->width = 0;
	info->type = 0;
	info->char_count = 0;
}

int		flag_parse(const char *input, int i, t_info *info, va_list args_pt)
{
	while (input[i])
	{
		if (input[i] == '0' && info->width == 0 && info->minus == 0)
			info->zero = 1;
		else if (input[i] == '-')
			flag_parse_minus(info);
		else if (input[i] == '*')
			flag_parse_width(info, args_pt);
		else if (ft_isdigit(input[i]))
			i = flag_parse_digit(input, i, info);
		else if (input[i] == '.')
			i = flag_parse_dot(input, ++i, info, args_pt);
		else if (is_in_type_list(input[i]))
		{
			info->type = input[i];
			break ;
		}
		else if (!ft_isdigit(input[i]) && !is_in_type_list(input[i])
			&& !is_in_flag_list(input[i]))
			break ;
		i++;
	}
	return (i);
}

void	print_and_cal_input(t_info *info, va_list args_pt, char type)
{
	if (type == 'c')
		print_char(va_arg(args_pt, int), info);
	else if (type == 's')
	 	print_string(va_arg(args_pt, char *), info);
	else if (type == 'd' || type == 'i')
		print_int(va_arg(args_pt, int), info);
	else if (type == 'u')
	 	print_unsigned_int(va_arg(args_pt, unsigned int), info);
	// else if (type == 'x' || type == 'X')
	// 	print_hexa(va_arg(args_pt, unsigned int), type, info);
	// else if (type == 'p')
	// 	print_pointer(va_arg(args_pt, unsigned long long), info);
	// else if (type == '%')
	// 	print_percent(info);
}


