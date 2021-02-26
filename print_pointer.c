/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sajeon </var/mail/sajeon>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 20:02:27 by sajeon            #+#    #+#             */
/*   Updated: 2021/02/26 20:55:38 by sajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char *hex_base_change(unsigned long long pt, char *base)
{
	char *rst;
	int len;
	unsigned long long temp_pt;

	temp_pt = pt;
	len = 1;
	while (temp_pt > 15)
	{
		temp_pt /= 16;
		len++;
	}
	if (!(rst = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	rst[len] = '\0';
	len--;
	while (len >= 0)
	{
		rst[len] = *(base + pt % 16);
		pt /= 16;
		len--;
	}
	return (rst);
}

static void print_pointer_indent(t_info *info, int max_len)
{
	if (info->zero && !info->minus && info->dot < 0)
		cal_width(info, info->width, max_len + 2, 1);
	else
        cal_width(info, info->width, max_len + 2, 0);
}

static void print_padd_pointer(char *str_pt, t_info *info)
{
    int i;

    i = 0;
	put_char_count('0', info);
	put_char_count('x', info);
	if (info->dot >= 0)
		cal_width(info, info->dot, (int)ft_strlen(str_pt), 1);
	else
		cal_width(info, info->dot, (int)ft_strlen(str_pt), 0);
    while (i < (int)ft_strlen(str_pt))      
		put_char_count(str_pt[i++], info);
}

void	print_pointer(unsigned long long pt, t_info *info)
{
	char	*str_pt;
	int		num_len;
	int		max_len;
	
	if (info->dot == 0 && pt == 0)
	{
		if (info->minus == 0)
			cal_width(info, info->width, 2, 0);
		put_char_count('0', info);
		put_char_count('x', info);
		if (info->minus == 1)
			cal_width(info, info->width, 2, 0);
		return ;
	}
	str_pt = hex_base_change(pt, "0123456789abcdef");
	num_len = (int)ft_strlen(str_pt);
	max_len = (info->dot >= (int)ft_strlen(str_pt)) ? info->dot : num_len;
    if (info->minus == 0)
        print_pointer_indent(info, max_len);
    print_padd_pointer(str_pt, info);
    if (info->minus == 1)
        print_pointer_indent(info, max_len);
	free(str_pt);
}
