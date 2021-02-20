/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sajeon <sajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 22:02:20 by sajeon            #+#    #+#             */
/*   Updated: 2021/02/20 17:21:23 by sajeon           ###   ########.fr       */
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

int	ft_printf(const char *input, ...);

#endif