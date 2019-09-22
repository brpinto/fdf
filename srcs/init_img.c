/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brpinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 18:40:36 by brpinto           #+#    #+#             */
/*   Updated: 2019/03/14 14:15:27 by brpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	init_img(t_env *env)
{
	env->img.img_ptr = mlx_new_image(env->dis, WIN_WIDTH, WIN_HEIGHT);
	env->img.data = (unsigned char*)mlx_get_data_addr(env->img.img_ptr,
			&env->img.bpp, &env->img.size_l, &env->img.endian);
	ft_create_img(env);
	mlx_put_image_to_window(env->dis, env->win, env->img.img_ptr, 0, 0);
	mlx_destroy_image(env->dis, env->img.img_ptr);
	return (0);
}
