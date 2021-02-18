/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sajeon <sajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 01:21:28 by sajeon            #+#    #+#             */
/*   Updated: 2020/12/27 04:08:47 by sajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	num_len(int n)
{
	size_t i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i + 1);
}

int		ft_pow(size_t base, size_t pow)
{
	int val;

	val = 1;
	while (pow--)
		val *= base;
	return (val);
}

void	if_minus(char *rst, int *n, size_t *len, size_t *i)
{
	rst[0] = '-';
	*n *= -1;
	*i += 1;
	*len -= 1;
}

char	*ft_itoa(int n)
{
	char	*rst;
	size_t	len;
	size_t	i;

	i = 0;
	len = num_len(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (!(rst = malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (n < 0)
		if_minus(rst, &n, &len, &i);
	while (len)
	{
		rst[i] = (n / ft_pow(10, len - 1)) + '0';
		n %= ft_pow(10, len - 1);
		i++;
		len--;
	}
	rst[i] = '\0';
	return (rst);
}
