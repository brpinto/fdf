/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brpinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 14:33:16 by brpinto           #+#    #+#             */
/*   Updated: 2019/03/14 15:14:00 by brpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	**ft_malloc_2d(int size_1d, int size_2d)
{
	int i;
	int **tab;

	tab = NULL;
	i = 0;
	if (!(tab = (int **)malloc(sizeof(int *) * size_1d)))
		return (0);
	while (i < size_1d)
	{
		if (!(tab[i] = (int *)malloc(sizeof(int) * size_2d)))
			return (0);
		i++;
	}
	return (tab);
}
