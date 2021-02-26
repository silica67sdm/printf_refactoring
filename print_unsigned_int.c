/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sajeon </var/mail/sajeon>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 14:09:50 by sajeon            #+#    #+#             */
/*   Updated: 2021/02/26 15:54:09 by sajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_unsigned_itoa(unsigned int n)
{
	char	*rst;
	int		len;
	unsigned int temp_n;

	temp_n = n;
	len = 1;
	while (temp_n > 9)
	{
		temp_n /= 10;
		len++;
	}
	if (!(rst = malloc(sizeof(char) * (len + 1))))
			return (NULL);
	rst[len] = '\0';
	len--;
	while (len >= 0)
	{
		rst[len] = n % 10 + '0';
		n /= 10;
		len--;
	}
	return (rst);
}

static void print_unsigned_int_indent(t_info *info, int max_len)
{
	if (info->zero && !info->minus && info->dot < 0)
		cal_width(info, info->width, max_len, 1);
	else
        cal_width(info, info->width, max_len, 0);
}

static void print_padd_unsigned_int(char *str_n, t_info *info)
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

void	print_unsigned_int(unsigned int n, t_info *info)
{
	char	*str_n;
	int		num_len;
	int		max_len;

	str_n = ft_unsigned_itoa(n);
	num_len = (int)ft_strlen(str_n);
	max_len = (info->dot >= (int)ft_strlen(str_n)) ? info->dot : num_len;
    if (info->dot == 0 && n == 0)
    {
        cal_width(info, info->width, 0, 0);
        return ;
    }
    if (info->minus == 0)
        print_unsigned_int_indent(info, max_len);
    print_padd_unsigned_int(str_n, info);
    if (info->minus == 1)
        print_unsigned_int_indent(info, max_len);
	free(str_n);
}
