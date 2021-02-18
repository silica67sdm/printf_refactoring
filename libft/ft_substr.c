/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sajeon <sajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 13:08:06 by sajeon            #+#    #+#             */
/*   Updated: 2020/12/31 17:46:57 by sajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	m_len;
	char	*rst;

	if (!s || ft_strlen(s) <= start || !len)
		return (ft_strdup(""));
	if ((start + len) >= ft_strlen(s))
		m_len = ft_strlen(s) - start;
	else
		m_len = len;
	if (!(rst = malloc(sizeof(char) * m_len + 1)))
		return (NULL);
	ft_memcpy(rst, &s[start], m_len);
	rst[m_len] = '\0';
	return (rst);
}
