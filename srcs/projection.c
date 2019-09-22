/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_projection.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brpinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 18:38:48 by brpinto           #+#    #+#             */
/*   Updated: 2019/03/14 15:16:57 by brpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	ft_iso(int *x, int *y, int z)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}

void	ft_rot_x(t_env *env, int *y, int *z)
{
	int previous_y;
	int previous_z;

	previous_y = *y;
	previous_z = *z;
	*y = (previous_y * cos(env->cam.rot_x)) + (previous_z
			* sin(env->cam.rot_x));
	*z = (-previous_y * sin(env->cam.rot_x)) + (previous_z
			* cos(env->cam.rot_x));
}

void	ft_rot_y(t_env *env, int *x, int *z)
{
	int previous_x;
	int previous_z;

	previous_x = *x;
	previous_z = *z;
	*x = (previous_x * cos(env->cam.rot_y)) + (previous_z
			* sin(env->cam.rot_y));
	*z = (-previous_x * sin(env->cam.rot_y)) + (previous_z
			* cos(env->cam.rot_y));
}

void	ft_rot_z(t_env *env, int *x, int *y)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x * cos(env->cam.rot_z)) - (previous_y
			* sin(env->cam.rot_z));
	*y = (previous_x * sin(env->cam.rot_z)) + (previous_y
			* cos(env->cam.rot_z));
}
