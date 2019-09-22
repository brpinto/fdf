/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brpinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 16:52:06 by brpinto           #+#    #+#             */
/*   Updated: 2019/03/19 03:08:26 by brpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void		manage_color(t_env *env, int key)
{
	if (key == 8)
		env->cam.val += 3;
	else if (key == 11)
		env->cam.bgt += 1;
	else if (key == 45)
		env->cam.bgt -= 1;
	else if (key == 43)
		env->cam.sat += 1;
	else if (key == 47)
		env->cam.sat -= 1;
}

static	void	manage_rot(t_env *env, int key)
{
	if (key == 126)
		env->cam.rot_x -= 0.0523599;
	else if (key == 125)
		env->cam.rot_x += 0.0523599;
	else if (key == 123)
		env->cam.rot_y += 0.0523599;
	else if (key == 124)
		env->cam.rot_y -= 0.0523599;
	else if (key == 78)
		env->cam.rot_z -= 0.0523599;
	else if (key == 69)
		env->cam.rot_z += 0.0523599;
}

static	void	manage_translate(t_env *env, int key)
{
	if (key == 13 && env->cam.margin_y >= -(env->cam.space
				* env->map.row_sum))
		env->cam.margin_y -= 20;
	else if (key == 1 && env->cam.margin_y <= WIN_HEIGHT)
		env->cam.margin_y += 20;
	else if (key == 2 && env->cam.margin_x <= WIN_WIDTH)
		env->cam.margin_x += 20;
	else if (key == 0 && (env->cam.margin_x >= -(env->cam.space
					* env->map.col_sum)))
		env->cam.margin_x -= 20;
}

static	void	reset(t_env *env)
{
	env->cam.rot_x = 0;
	env->cam.rot_y = 0;
	env->cam.rot_z = 0;
	if (env->cam.proj == ISO)
		env->cam.proj = ORT;
	env->cam.margin_x = (WIN_WIDTH - (env->cam.space * env->map.col_sum)) / 2;
	env->cam.margin_y = (WIN_HEIGHT - (env->cam.space * env->map.row_sum)) / 2;
	env->cam.bgt = 0;
	env->cam.sat = 0;
}

int				ft_key_press(int key, t_env *env)
{
	if (key == 53)
		exit(0);
	if (key == 13 || key == 1 || key == 2 || key == 0)
		manage_translate(env, key);
	if (key == 34)
		env->cam.proj = (env->cam.proj > 0 ? ORT : ISO);
	if (key == 125 || key == 126 || key == 123 || key == 124 || key == 78
			|| key == 69)
		manage_rot(env, key);
	if (key == 15)
		reset(env);
	if (key == 12 && env->cam.space >= 3)
		env->cam.space -= 5;
	if (key == 14)
		env->cam.space += 5;
	if (key == 8 || key == 11 || key == 45 || key == 43 || key == 47)
		manage_color(env, key);
	init_img(env);
	return (0);
}
