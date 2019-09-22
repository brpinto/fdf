/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brpinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 15:25:31 by brpinto           #+#    #+#             */
/*   Updated: 2019/03/18 22:22:21 by brpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static	void	count(t_map *map, t_list **file)
{
	t_list *tmp;

	tmp = *file;
	map->col_sum = ft_word_count(tmp->content, ' ');
	while (tmp->next)
	{
		map->row_sum++;
		tmp = tmp->next;
	}
	map->row_sum++;
	map->pts_sum = (map->row_sum + 1) * map->col_sum;
}

static	void	fill_tab(t_env *env, t_list **file)
{
	int		i;
	char	**split;
	t_list	*tmp;

	tmp = *file;
	i = 0;
	env->map.y = 0;
	while (tmp)
	{
		env->map.x = 0;
		split = ft_strsplit((char *)tmp->content, ' ');
		while (split[env->map.x] != NULL)
		{
			env->map.map[i][0] = env->map.x;
			env->map.map[i][1] = env->map.y;
			env->map.map[i][2] = ft_atoi(split[env->map.x]);
			free(split[env->map.x]);
			i++;
			env->map.x++;
		}
		free(split);
		env->map.y++;
		tmp = tmp->next;
	}
}

int				init_map(t_env *env, int fd)
{
	int		i;
	t_list	*file;

	i = 0;
	if (!(file = check_file(fd)))
		return (0);
	count(&env->map, &file);
	env->map.map = ft_malloc_2d(env->map.pts_sum, 3);
	fill_tab(env, &file);
	return (1);
}
