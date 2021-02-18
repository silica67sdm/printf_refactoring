/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sajeon <sajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 13:19:43 by sajeon            #+#    #+#             */
/*   Updated: 2021/01/03 19:40:09 by sajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t srclen;

	srclen = ft_strlen(src);
	if (!dest || !src)
		return (0);
	if (!dstsize)
		return (srclen);
	else if (srclen < dstsize - 1)
		ft_memcpy(dest, src, srclen + 1);
	else if (dstsize != 0)
	{
		ft_memcpy(dest, src, dstsize - 1);
		dest[dstsize - 1] = '\0';
	}
	return (srclen);
}
