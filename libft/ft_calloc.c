/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sajeon <sajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 02:27:32 by sajeon            #+#    #+#             */
/*   Updated: 2020/12/30 22:27:15 by sajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*dst;
	size_t	len;

	len = nmemb * size;
	if (!(dst = malloc(len)))
		return (0);
	ft_bzero(dst, len);
	return (dst);
}
