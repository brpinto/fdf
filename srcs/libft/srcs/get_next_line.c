/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brpinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 13:26:56 by brpinto           #+#    #+#             */
/*   Updated: 2019/03/18 22:29:22 by brpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>
#include <stdio.h>

static t_list	*check_fd(t_list **save, int fd)
{
	t_list *tmp;

	tmp = *save;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("\0", fd);
	ft_lstadd(save, tmp);
	return (tmp);
}

static int		check_end(t_list *current, char **line, int ret)
{
	size_t	i;
	int		value;
	char	*tmp;

	i = 0;
	value = 1;
	tmp = NULL;
	if (ret < BUFF_SIZE && !ft_strlen(current->content))
		value = 0;
	while (((char*)current->content)[i] != '\n'
			&& ((char*)current->content)[i] != '\0')
		i++;
	*line = ft_strsub(current->content, 0, i);
	if (i < ft_strlen(current->content) - 1)
	{
		tmp = ft_strdup(current->content + i + 1);
		free(current->content);
		current->content = tmp;
	}
	else
		ft_strclr(current->content);
	return (value);
}

int				get_next_line(const int fd, char **line)
{
	char			*buff;
	int				ret;
	static t_list	*save;
	t_list			*current;

	ret = 0;
	buff = NULL;
	if (fd < 0 || !line || BUFF_SIZE < 0 || read(fd, buff, 0) < 0)
		return (-1);
	if (!(buff = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	if (!(current = check_fd(&save, fd)))
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		current->content = ft_strjoin_free(current->content, buff, 1);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	free(buff);
	return (check_end(current, line, ret));
}
