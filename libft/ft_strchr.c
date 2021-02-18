/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sajeon <sajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 18:49:38 by sajeon            #+#    #+#             */
/*   Updated: 2020/12/30 22:32:42 by sajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (char *)(str + i);
		i++;
	}
	if (str[i] == '\0' && c == '\0')
		return (char *)(str + i);
	return (0);
}
