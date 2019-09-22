/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brpinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 14:34:15 by brpinto           #+#    #+#             */
/*   Updated: 2019/03/19 01:38:59 by brpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static	void	first_tier(t_env *env, int height, int pixel)
{
	env->img.data[pixel + 1] = (height * 255 / 120 + env->cam.sat) > 255 ?
		255 : (height * 255 / 120 + env->cam.sat);
	env->img.data[pixel + 2] = (255 - env->img.data[pixel + 1]
		+ env->cam.sat) > 255 ? 255 : (255 - env->img.data[pixel + 1]
			+ env->cam.sat);
	env->img.data[pixel] = (0 + env->cam.sat) > 255 ? 255 : (0 + env->cam.sat);
	env->img.data[pixel + 3] = env->cam.bgt;
}

static	void	second_tier(t_env *env, int height, int pixel)
{
	env->img.data[pixel + 2] = (0 + env->cam.sat) > 255 ?
		255 : (0 + env->cam.sat);
	env->img.data[pixel] = ((height - 120) * 255 / 120 + env->cam.sat) > 255 ?
		255 : ((height - 120) * 255 / 120 + env->cam.sat);
	env->img.data[pixel + 1] = (255 - env->img.data[pixel] + env->cam.sat)
		> 255 ? 255 : (255 - env->img.data[pixel] + env->cam.sat);
	env->img.data[pixel + 3] = env->cam.bgt;
}

static	void	third_tier(t_env *env, int height, int pixel)
{
	env->img.data[pixel + 2] = ((height - 240) * 255 / 120 + env->cam.sat)
		> 255 ? 255 : ((height - 240) * 255 / 120 + env->cam.sat);
	env->img.data[pixel] = (255 - env->img.data[pixel] + env->cam.sat) > 255 ?
		255 : (255 - env->img.data[pixel] + env->cam.sat);
	env->img.data[pixel + 1] = (0 + env->cam.sat) > 255 ? 255
		: (0 + env->cam.sat);
	env->img.data[pixel + 3] = env->cam.bgt;
}

void			get_color(t_env *env, int height, int pixel)
{
	height += env->cam.val;
	if (height < 0)
		height *= -1;
	while (height > 360)
		height -= 360;
	if (height < 120)
		first_tier(env, height, pixel);
	else if (height < 240)
		second_tier(env, height, pixel);
	else
		third_tier(env, height, pixel);
}
