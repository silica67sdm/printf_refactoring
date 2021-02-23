/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sajeon <sajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 16:57:10 by sajeon            #+#    #+#             */
/*   Updated: 2021/02/23 20:34:09 by sajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 테스트용 함수.
#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	ft_printf("[%5c]", 'a');

	// puts("--------------------------\n");
	// // printf("%05.32d");
	// ft_printf("%05.32d", 300);
	// puts("--------------------------\n");
	// // printf("%-5.32d");
	// ft_printf("%-5.32d", 200);
	// puts("--------------------------\n");
	// // printf("%-*.32d");
	// ft_printf("%-*.32d", 125, 200);
	// puts("--------------------------\n");
	// // printf("%-*.32d");
	// ft_printf("%-*.32d", -125, 200);
	// puts("--------------------------\n");
	// // printf("%-25.*d");
	// ft_printf("%-25.*d", 31, 200);
	// puts("--------------------------\n");
	// // printf("%-25.*d");
	// ft_printf("%-25.*d", -31, 200);

	// printf("info.zero: %d\n", info.zero);
	// printf("info.minus: %d\n", info.minus);
	// printf("info.dot: %d\n", info.dot);
	// printf("info.width: %d\n", info.width);
	// printf("info.type: %c\n", (char)info.type);
	// printf("info.char_count: %d\n", info.char_count);

	return (0);
}