/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brpinto <brpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 17:07:53 by brpinto           #+#    #+#             */
/*   Updated: 2018/12/29 16:37:11 by brpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int i;
	int j;
	int s1_len;

	i = 0;
	j = 0;
	s1_len = ft_strlen(s1);
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
	{
		s1[s1_len] = s2[j];
		s1_len++;
		j++;
	}
	s1[s1_len] = '\0';
	return (s1);
}
