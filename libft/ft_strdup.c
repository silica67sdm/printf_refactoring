/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sajeon <sajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 02:17:54 by sajeon            #+#    #+#             */
/*   Updated: 2020/12/30 22:30:51 by sajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char *dst;

	if (!(dst = (char *)malloc(ft_strlen(s) + 1)))
		return (0);
	ft_memcpy(dst, s, ft_strlen(s));
	*(dst + ft_strlen(s)) = '\0';
	return (dst);
}
