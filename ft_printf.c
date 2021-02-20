/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sajeon <sajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 21:50:39 by sajeon            #+#    #+#             */
/*   Updated: 2021/02/20 15:27:52 by sajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(void)
{
	int test = 1;
	char test_str[40] = "hello";
	char dest[40];

	printf("%d\n", test);
	printf("%s\n", test_str);
	printf("%s\n", ft_memcpy(dest, test_str, 5));
	return (1);
}
