/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sajeon <sajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 14:52:50 by sajeon            #+#    #+#             */
/*   Updated: 2021/01/03 16:21:30 by sajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_cpy;
	unsigned char	*src_cpy;

	dest_cpy = (unsigned char *)dest;
	src_cpy = (unsigned char *)src;
	if (dest_cpy > src_cpy)
	{
		dest_cpy = dest_cpy + n;
		src_cpy = src_cpy + n;
		while (n-- > 0)
			*(--dest_cpy) = *(--src_cpy);
	}
	else if (dest_cpy < src_cpy)
	{
		dest = ft_memcpy(dest_cpy, src_cpy, n);
	}
	return (dest);
}
