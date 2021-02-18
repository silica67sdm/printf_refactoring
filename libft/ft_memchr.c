/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sajeon <sajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 04:15:27 by sajeon            #+#    #+#             */
/*   Updated: 2020/12/30 20:37:31 by sajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_c;
	unsigned int	i;

	s_c = (unsigned char *)s;
	i = 0;
	while (i < n && s_c[i] != (unsigned char)c)
		i++;
	if (i == n)
		return (NULL);
	return ((void *)&s_c[i]);
}
