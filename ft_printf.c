/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sajeon <sajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 21:50:39 by sajeon            #+#    #+#             */
/*   Updated: 2021/02/25 15:55:57 by sajeon           ###   ########.fr       */
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

void	print_and_cal_input(t_info *info, va_list args_pt, char type)
{
	if (type == 'c')
		print_char(va_arg(args_pt, int), info);
	else if (type == 's')
	 	print_string(va_arg(args_pt, char *), info);
	// else if (type == 'd' || type == 'i')
	// 	print_int(va_arg(args_pt, int), info);
	// else if (type == 'u')
	// 	print_usigned_int(va_arg(args_pt, unsigned int), info);
	// else if (type == 'x' || type == 'X')
	// 	print_hexa(va_arg(args_pt, unsigned int), type, info);
	// else if (type == 'p')
	// 	print_pointer(va_arg(args_pt, unsigned long long), info);
	// else if (type == '%')
	// 	print_percent(info);
}

void	cal_width(t_info *info, int input_len)
{
	int fill_type;

	fill_type = info->zero ? '0' : ' ';
	while (info->width - input_len > 0)
	{
		put_char_count(fill_type, info);
		info->width -= 1;
	}
}

void	print_char(char k, t_info *info)
{
	if (info->minus == 1)
		put_char_count(k, info);
	cal_width(info, 1);
	if (info->minus == 0)
		put_char_count(k, info);
}

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
	cal_width(info, prec);
	if (info->minus == 0)
		while (i < prec)
		{
			put_char_count(str[i], info);
			i++;
		}
}

void	put_char_count(int k, t_info *info)
{
	ft_putchar_fd(k, 1);
	info->char_count += 1;
}

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
