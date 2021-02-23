/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sajeon <sajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 22:02:20 by sajeon            #+#    #+#             */
/*   Updated: 2021/02/23 16:54:02 by sajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h> // **** only for testing ****
#include "libft/libft.h"
#include <stdarg.h>

typedef struct s_info
{
    int zero;
    int minus;
	int dot;
    int star;
    int width;
	int type;
    int char_count;
}              t_info;

void	init_info(t_info *info);
void	flag_parse_minus(t_info *info);
int		flag_parse_dot(const char *input, int i, t_info *info, va_list args_pt);
void	flag_parse_width(t_info *info, va_list args_pt);
int		flag_parse_digit(const char *input, int i, t_info *info);
int		is_in_type_list(int k);
int		is_in_flag_list(int k);
int	    flag_parse(const char *input, int i, t_info *info, va_list args);
int	    ft_printf(const char *input, ...);

#endif