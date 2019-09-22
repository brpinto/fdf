/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brpinto <brpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:27:45 by brpinto           #+#    #+#             */
/*   Updated: 2018/11/29 14:51:10 by brpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strtrim(char const *s)
{
	size_t start;
	size_t len;

	if (!s)
		return (NULL);
	start = 0;
	len = ft_strlen(s) - 1;
	while (s[start] && (s[start] == '\t' ||
				s[start] == '\n' || s[start] == ' '))
		start++;
	if (start == len + 1)
		return (ft_strnew(0));
	while (s[len] == '\t' || s[len] == '\n' || s[len] == ' ')
		len--;
	return (ft_strsub(s, (unsigned int)start,
				(size_t)(len - start + 1)));
}
