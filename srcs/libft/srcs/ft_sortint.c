/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brpinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 14:04:31 by brpinto           #+#    #+#             */
/*   Updated: 2018/11/30 17:44:06 by brpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sortint(int *tab, int size)
{
	int i;

	i = 0;
	if (!tab || !size)
		return ;
	while (size >= 0)
	{
		while (i < size)
		{
			if (tab[i] > tab[size - 1])
				ft_swap(&tab[i], &tab[size - 1]);
			i++;
		}
		size--;
		i = 0;
	}
}
