/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brpinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:40:53 by brpinto           #+#    #+#             */
/*   Updated: 2018/12/29 16:39:13 by brpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char const *s1, char const *s2, int i)
{
	char *str;

	str = NULL;
	if (!s1 || !s2 || !i)
		return (NULL);
	str = ft_strjoin(s1, s2);
	if (i == 1)
		free((char*)s1);
	else if (i == 2)
		free((char*)s2);
	else if (i == 3)
	{
		free((char*)s1);
		free((char*)s2);
	}
	return (str);
}
