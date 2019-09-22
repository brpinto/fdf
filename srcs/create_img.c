/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brpinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 12:57:36 by brpinto           #+#    #+#             */
/*   Updated: 2019/03/18 22:06:50 by brpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void		draw_columns(t_env *env)
{
	env->map.x = 0;
	while (env->map.x < env->map.col_sum)
	{
		env->map.y = 0;
		origin_point(env);
		while (env->map.y < env->map.row_sum - 1)
		{
			env->current = env->start;
			next_point_col(env);
			ft_bresenham(env);
			env->start = env->end;
			env->map.y++;
		}
		env->map.x++;
	}
}

static void		draw_lines(t_env *env)
{
	env->map.y = 0;
	while (env->map.y < env->map.row_sum)
	{
		env->map.x = 0;
		origin_point(env);
		while (env->map.x < env->map.col_sum - 1)
		{
			env->current = env->start;
			next_point_line(env);
			ft_bresenham(env);
			env->start = env->end;
			env->map.x++;
		}
		env->map.y++;
	}
}

void			ft_create_img(t_env *env)
{
	draw_lines(env);
	draw_columns(env);
}
