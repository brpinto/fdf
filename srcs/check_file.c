/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brpinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 12:42:52 by brpinto           #+#    #+#             */
/*   Updated: 2019/03/19 02:49:12 by brpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static	void	ft_error(int error)
{
	if (error == 1)
		ft_putendl("Invalid length or invalid data");
	if (error == 2)
		ft_putendl("No data found");
	exit(0);
}

static	int		check_col(t_list **file)
{
	t_list	*tmp;
	int		size;

	tmp = *file;
	size = ft_word_count((char *)tmp->content, ' ');
	while (tmp)
	{
		if (size != ft_word_count((char *)tmp->content, ' '))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static	int		check_content(t_list **file)
{
	t_list	*tmp;
	int		i;
	char	*s;

	tmp = *file;
	while (tmp)
	{
		s = (char *)tmp->content;
		i = 0;
		while (s[i] != '\0')
		{
			if (s[i] != ' ' && s[i] == '-')
			{
				if ((s[i + 1] >= '!' && s[i + 1] <= '/') || (s[i + 1] >= ':'
							&& s[i + 1] <= '~'))
					return (0);
			}
			else if ((s[i] >= '!' && s[i] <= '/') || (s[i] >= ':'
						&& s[i] <= '~'))
				return (0);
			i++;
		}
		tmp = tmp->next;
	}
	return (1);
}

static	void	add_link(t_list **file, t_list *new)
{
	t_list	*current;

	if (!*file)
		*file = new;
	else
	{
		current = *file;
		while (current->next)
			current = current->next;
		current->next = new;
	}
}

t_list			*check_file(int fd)
{
	t_list	*file;
	t_list	*new;
	int		len;
	char	*line;
	int		ret;

	file = NULL;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		len = ft_strlen(line);
		if (file == NULL)
			file = ft_lstnew(line, len);
		else
		{
			if (!check_col(&file) || !check_content(&file))
				ft_error(1);
			new = ft_lstnew(line, len);
			add_link(&file, new);
		}
		free(line);
	}
	free(line);
	ret <= 0 && len == 0 ? ft_error(2) : 0;
	return (file);
}
