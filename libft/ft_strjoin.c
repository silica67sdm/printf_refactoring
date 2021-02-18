/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sajeon <sajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 14:24:04 by sajeon            #+#    #+#             */
/*   Updated: 2020/12/31 17:00:54 by sajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *rst;

	if (!(rst = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1)))
		return (NULL);
	ft_memcpy(rst, s1, ft_strlen(s1));
	ft_memcpy(rst + ft_strlen(s1), s2, ft_strlen(s2));
	*(rst + ft_strlen(s1) + ft_strlen(s2)) = '\0';
	return (rst);
}
