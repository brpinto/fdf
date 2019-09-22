/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brpinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 20:56:51 by brpinto           #+#    #+#             */
/*   Updated: 2019/03/14 16:14:37 by brpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static	void	put_pixel(t_env *env, int x, int y, int z)
{
	int pixel;

	if (x > 0 && x < WIN_WIDTH && y > 0 && y < WIN_HEIGHT)
	{
		pixel = (x * 4) + (4 * WIN_WIDTH * y);
		get_color(env, z, pixel);
	}
}

void			ft_bresenham(t_env *env)
{
	env->delta.x = (abs(env->end.x - env->start.x));
	env->delta.sx = (env->start.x < env->end.x ? 1 : -1);
	env->delta.y = (abs(env->end.y - env->start.y));
	env->delta.sy = (env->start.y < env->end.y ? 1 : -1);
	env->delta.err = (env->delta.x > env->delta.y ?
			env->delta.x : -env->delta.y) / 2;
	while (1)
	{
		put_pixel(env, env->current.x, env->current.y, env->current.z);
		if (env->current.x == env->end.x && env->current.y == env->end.y)
			break ;
		env->delta.e2 = env->delta.err;
		if (env->delta.e2 > -env->delta.x)
		{
			env->delta.err -= env->delta.y;
			env->current.x += env->delta.sx;
		}
		if (env->delta.e2 < env->delta.y)
		{
			env->delta.err += env->delta.x;
			env->current.y += env->delta.sy;
		}
	}
}
