/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brpinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 18:35:27 by brpinto           #+#    #+#             */
/*   Updated: 2018/11/30 18:40:53 by brpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstsize(t_list *lst)
{
	size_t lst_s;

	if (!lst)
		return (0);
	lst_s = 0;
	while (lst)
	{
		lst_s++;
		lst = lst->next;
	}
	return (lst_s);
}
