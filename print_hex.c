/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sajeon <sajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 16:09:29 by sajeon            #+#    #+#             */
/*   Updated: 2021/02/26 23:14:15 by sajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*hex_base_change(unsigned int n, char *base)
{
	char			*rst;
	int				len;
	unsigned int	temp_n;

	temp_n = n;
	len = 1;
	while (temp_n > 15)
	{
		temp_n /= 16;
		len++;
	}
	if (!(rst = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	rst[len] = '\0';
	len--;
	while (len >= 0)
	{
		rst[len] = *(base + n % 16);
		n /= 16;
		len--;
	}
	return (rst);
}

static void	print_hex_indent(t_info *info, int max_len)
{
	if (info->zero && !info->minus && info->dot < 0)
		cal_width(info, info->width, max_len, 1);
	else
		cal_width(info, info->width, max_len, 0);
}

static void	print_padd_hex(char *str_n, t_info *info)
{
	int i;

	i = 0;
	if (info->dot >= 0)
		cal_width(info, info->dot, (int)ft_strlen(str_n), 1);
	else
		cal_width(info, info->dot, (int)ft_strlen(str_n), 0);
	while (i < (int)ft_strlen(str_n))
		put_char_count(str_n[i++], info);
}

void		print_hex(unsigned int n, t_info *info, char type)
{
	char	*str_n;
	int		num_len;
	int		max_len;

	if (type == 'x')
		str_n = hex_base_change(n, "0123456789abcdef");
	else if (type == 'X')
		str_n = hex_base_change(n, "0123456789ABCDEF");
	num_len = (int)ft_strlen(str_n);
	max_len = (info->dot >= num_len) ? info->dot : num_len;
	if (info->dot == 0 && n == 0)
	{
		cal_width(info, info->width, 0, 0);
		return ;
	}
	if (info->minus == 0)
		print_hex_indent(info, max_len);
	print_padd_hex(str_n, info);
	if (info->minus == 1)
		print_hex_indent(info, max_len);
	free(str_n);
}
