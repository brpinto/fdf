/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brpinto <brpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 18:25:21 by brpinto           #+#    #+#             */
/*   Updated: 2018/11/29 13:21:43 by brpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int		i;
	size_t	j;
	int		s1_len;

	i = 0;
	j = 0;
	s1_len = ft_strlen(s1);
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0' && j < n)
	{
		s1[s1_len] = s2[j];
		s1_len++;
		j++;
	}
	s1[s1_len] = '\0';
	return (s1);
}
