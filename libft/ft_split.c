/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sajeon <sajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 15:02:49 by sajeon            #+#    #+#             */
/*   Updated: 2021/01/03 20:34:39 by sajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	count_words(char *str, char sep)
{
	long long cnt;

	cnt = 0;
	while (*str)
	{
		while (*str && *str == sep)
			str++;
		if (*str && *str != sep)
		{
			cnt++;
			while (*str && *str != sep)
				str++;
		}
	}
	return (cnt);
}

char		*malloc_word(char *str, char sep)
{
	char	*word;
	int		i;

	i = 0;
	while (str[i] && str[i] != sep)
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] && str[i] != sep)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

void		*leak(char **rst, int words)
{
	int	i;

	i = 0;
	while (i < words)
	{
		free(rst[i]);
		i++;
	}
	free(rst);
	return (NULL);
}

char		**ft_split(char const *s, char c)
{
	char	**rst;
	int		i;

	rst = (char **)malloc(sizeof(char *) * (count_words((char *)s, c) + 1));
	if (!rst)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			if (!(rst[i] = malloc_word((char *)s, c)))
				return (leak(rst, i));
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	rst[i] = NULL;
	return (rst);
}
