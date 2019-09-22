/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brpinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 16:38:21 by brpinto           #+#    #+#             */
/*   Updated: 2018/11/30 17:43:05 by brpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strrev(char *str)
{
	int		i;
	int		str_len;
	char	temp;

	i = 0;
	str_len = 0;
	if (!str)
		return (NULL);
	str_len = ft_strlen(str) - 1;
	while (i < str_len)
	{
		temp = str[i];
		str[i] = str[str_len];
		str[str_len] = temp;
		i++;
		str_len--;
	}
	return (str);
}
