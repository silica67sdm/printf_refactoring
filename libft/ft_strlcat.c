/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sajeon <sajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 14:19:12 by sajeon            #+#    #+#             */
/*   Updated: 2020/12/30 22:31:47 by sajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t idx;
	size_t dst_len;
	size_t src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (!size)
		return (src_len);
	else if (size < dst_len + 1)
		return (src_len + size);
	idx = 0;
	while (src[idx] && idx < size - dst_len - 1)
	{
		dst[dst_len + idx] = src[idx];
		idx++;
	}
	dst[dst_len + idx] = '\0';
	return (dst_len + src_len);
}
