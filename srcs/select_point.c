/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_point.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brpinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 14:26:07 by brpinto           #+#    #+#             */
/*   Updated: 2019/03/14 16:14:40 by brpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void		next_point_col(t_env *env)
{
	env->end.x = (env->map.map[(env->map.y + 1) * env->map.col_sum
			+ env->map.x][0] * env->cam.space);
	env->end.y = (env->map.map[(env->map.y + 1) * env->map.col_sum
			+ env->map.x][1] * env->cam.space);
	env->end.z = env->map.map[(1 + env->map.y) * env->map.col_sum
		+ env->map.x][2];
	ft_rot_x(env, &env->end.y, &env->end.z);
	ft_rot_y(env, &env->end.x, &env->end.z);
	ft_rot_z(env, &env->end.x, &env->end.y);
	if (env->cam.proj == ISO)
		ft_iso(&env->end.x, &env->end.y, env->end.z);
	env->end.x += env->cam.margin_x;
	env->end.y += env->cam.margin_y;
}

void		next_point_line(t_env *env)
{
	env->end.x = (env->map.map[env->map.y * env->map.col_sum
			+ env->map.x + 1][0] * env->cam.space);
	env->end.y = (env->map.map[env->map.y * env->map.col_sum
			+ env->map.x + 1][1] * env->cam.space);
	env->end.z = env->map.map[env->map.y * env->map.col_sum
		+ env->map.x + 1][2];
	ft_rot_x(env, &env->end.y, &env->end.z);
	ft_rot_y(env, &env->end.x, &env->end.z);
	ft_rot_z(env, &env->end.x, &env->end.y);
	if (env->cam.proj == ISO)
		ft_iso(&env->end.x, &env->end.y, env->end.z);
	env->end.x += env->cam.margin_x;
	env->end.y += env->cam.margin_y;
}

void		origin_point(t_env *env)
{
	env->start.x = (env->map.map[env->map.y * env->map.col_sum
			+ env->map.x][0] * env->cam.space);
	env->start.y = (env->map.map[env->map.y * env->map.col_sum
			+ env->map.x][1] * env->cam.space);
	env->start.z = env->map.map[env->map.y * env->map.col_sum
		+ env->map.x][2];
	ft_rot_x(env, &env->start.y, &env->start.z);
	ft_rot_y(env, &env->start.x, &env->start.z);
	ft_rot_z(env, &env->start.x, &env->start.y);
	if (env->cam.proj == ISO)
		ft_iso(&env->start.x, &env->start.y, env->start.z);
	env->start.x += env->cam.margin_x;
	env->start.y += env->cam.margin_y;
}
