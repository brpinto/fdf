/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brpinto <brpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 10:00:18 by brpinto           #+#    #+#             */
/*   Updated: 2018/11/29 18:31:52 by brpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		nb_len(int n)
{
	int len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static	char	*ft_fill(char *nb, long n_cpy, int len)
{
	while (n_cpy)
	{
		nb[--len] = n_cpy % 10 + '0';
		n_cpy /= 10;
	}
	return (nb);
}

char			*ft_itoa(int n)
{
	char			*nb;
	int				len;
	long			n_cpy;

	len = nb_len(n);
	nb = NULL;
	n_cpy = n;
	if (!(nb = ft_memalloc(len + 1)))
		return (NULL);
	nb[len] = '\0';
	if (n == 0)
	{
		nb[0] = '0';
		nb[1] = '\0';
	}
	else if (n < 0)
	{
		n_cpy = -n_cpy;
		nb[0] = '-';
	}
	nb = ft_fill(nb, n_cpy, len);
	return (nb);
}
