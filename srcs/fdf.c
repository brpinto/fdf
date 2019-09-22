/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brpinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 14:56:35 by brpinto           #+#    #+#             */
/*   Updated: 2019/03/18 22:04:26 by brpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static	void	init_cam(t_env *env)
{
	env->cam.proj = ORT;
	env->cam.space = 50;
	env->cam.margin_x = (WIN_WIDTH - (env->cam.space * env->map.col_sum)) / 2;
	env->cam.margin_y = (WIN_HEIGHT - (env->cam.space * env->map.row_sum)) / 2;
}

int				fdf(int fd)
{
	t_env env;

	ft_bzero(&env, sizeof(t_env));
	init_map(&env, fd);
	init_cam(&env);
	init_env(&env);
	return (0);
}
