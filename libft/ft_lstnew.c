/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sajeon <sajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 05:43:51 by sajeon            #+#    #+#             */
/*   Updated: 2020/12/31 21:27:07 by sajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *new_list;

	if (!(new_list = malloc(sizeof(t_list))))
		return (NULL);
	new_list->content = content;
	new_list->next = NULL;
	return (new_list);
}
