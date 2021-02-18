/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sajeon <sajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 20:00:00 by sajeon            #+#    #+#             */
/*   Updated: 2020/12/24 20:30:34 by sajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *block, int c, size_t size)
{
	char *tmp;

	tmp = block;
	while (size--)
	{
		*tmp = (char)c;
		tmp++;
	}
	return (block);
}
