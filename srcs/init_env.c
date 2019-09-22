/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brpinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 16:42:34 by brpinto           #+#    #+#             */
/*   Updated: 2019/03/19 02:05:35 by brpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	init_env(t_env *env)
{
	ft_bzero(env, sizeof(t_env *));
	env->dis = mlx_init();
	env->win = mlx_new_window(env->dis, WIN_WIDTH, WIN_HEIGHT, "Fdf");
	mlx_clear_window(env->dis, env->win);
	init_img(env);
	mlx_hook(env->win, 2, 0, ft_key_press, (void *)env);
	mlx_hook(env->win, 17, 0, ft_close, (void *)env);
	mlx_loop(env->dis);
}
