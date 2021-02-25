/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sajeon <sajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 21:03:08 by sajeon            #+#    #+#             */
/*   Updated: 2021/02/25 21:40:34 by sajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void print_int_indent(int except, t_info *info, int n, int max_len)
{
    if (n < 0)
    {
        if (info->minus == 0 && except)
            put_char_count('-', info);
        cal_width(info, info->width - 1, max_len, except);
    }
    else
        cal_width(info, info->width, max_len, except);
}

static void print_padd_int(char *str_n, int n, t_info *info, int except)
{
    int i;

    i = 0;
    if (n < 0 && !except)
    {
        put_char_count('-', info);
        n *= -1;
        info->dot += 1;
        i++;
    }
    if (except && n < 0)
        i++;
    if (info->dot < (int)ft_strlen(str_n))
        while (i < (int)ft_strlen(str_n))
            put_char_count(str_n[i++], info);
    else
    {
        cal_width(info, info->dot, (int)ft_strlen(str_n), 1);
        while (i < (int)ft_strlen(str_n))
            put_char_count(str_n[i++], info);
    }
}

void	print_int(int n, t_info *info)
{
	char	*str_n;
	int		num_len;
	int		max_len;
    int     except;

	str_n = ft_itoa(n);
	num_len = n >= 0 ? (int)ft_strlen(str_n) : (int)ft_strlen(str_n) - 1;
	max_len = (info->dot >= (int)ft_strlen(str_n)) ? info->dot : num_len;
    if (info->dot == 0 && n == 0)
    {
        cal_width(info, info->width, 0, 0);
        return ;
    }
    except = 0;
    if (info->zero && info->dot < 0 && info->minus == 0)
        except = 1;
    if (info->minus == 0)
        print_int_indent(except, info, n, max_len);
    print_padd_int(str_n, n, info, except);
    if (info->minus == 1)
        print_int_indent(except, info, n, max_len);
	free(str_n);
}