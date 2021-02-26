/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sajeon <sajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 16:57:10 by sajeon            #+#    #+#             */
/*   Updated: 2021/02/26 20:40:27 by sajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 테스트용 함수. 여러가지 예시에 대해서 테스트 할 수 있습니다.
// make test 명령어를 입력하면 해당 테스트에 대한 결과를 확인 할 수 있습니다.
// make test_clean 명령어를 입력하여 테스트 결과물들을 지울 수 있습니다.
#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	int pt = 1;
	// ft_printf("[%5c]", 'a');
	ft_printf("[hello, %s]", "gavin");
	printf("\n[pt address: %p]\n", &pt);
	ft_printf("\n[%p]\n", &pt);
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
