/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brpinto <brpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 10:10:27 by brpinto           #+#    #+#             */
/*   Updated: 2018/11/30 13:46:33 by brpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*begin;
	t_list	*current;

	if (!lst)
		return (NULL);
	if (!(begin = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	begin = f(lst);
	current = begin;
	while (lst->next)
	{
		lst = lst->next;
		current->next = f(lst);
		current = current->next;
	}
	return (begin);
}
