/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sajeon <sajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 06:46:06 by sajeon            #+#    #+#             */
/*   Updated: 2021/01/03 17:15:27 by sajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list *tmp;

	tmp = lst;
	if (lst == NULL)
		return (NULL);
	while (1)
	{
		if (!(tmp->next))
			break ;
		tmp = tmp->next;
	}
	return (tmp);
}
