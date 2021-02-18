/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sajeon <sajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 21:15:17 by sajeon            #+#    #+#             */
/*   Updated: 2020/12/31 21:12:43 by sajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		find_str(const char *str, const char *find, int n)
{
	str += n;
	while (*find)
	{
		if (*str != *find)
			return (0);
		str++;
		find++;
	}
	return (1);
}

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t	i;

	i = 0;
	if (!*find)
		return ((char *)str);
	if (!len)
		return (0);
	if (!*str)
		return (0);
	while (str[i] && (i + ft_strlen(find) <= len))
	{
		if (find_str(str, find, i))
			return ((char *)str + i);
		i++;
	}
	return (0);
}
