/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sajeon <sajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 21:50:39 by sajeon            #+#    #+#             */
/*   Updated: 2021/02/23 18:14:26 by sajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_info(t_info *info)
{
	info->zero = 0;
	info->minus = 0;
	info->dot = -1;
	info->width = 0;
	info->type = 0;
	info->char_count = 0;
}

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

int		ft_printf(const char *input, ...)
{
	va_list	args_pt;
	int		i;
	t_info	info;

	i = 0;
	va_start(args_pt, input);
	while (input[i])
	{
		init_info(&info);
		if (input[i] == '%' && input[i + 1])
		{
			i = flag_parse(input, ++i, &info, args_pt);
			// print_and_cal_input(&info, args_pt);
			printf("info.zero: %d\n", info.zero);
			printf("info.minus: %d\n", info.minus);
			printf("info.dot: %d\n", info.dot);
			printf("info.width: %d\n", info.width);
			printf("info.type: %c\n", (char)info.type);
			printf("info.char_count: %d\n", info.char_count);
		}
		else
		{
			ft_putchar_fd(input[i], 1);
			info.char_count++;
		}
		i++;
	}
	va_end(args_pt);
	return (info.char_count);
}
