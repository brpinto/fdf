/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brpinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 17:31:54 by brpinto           #+#    #+#             */
/*   Updated: 2019/03/19 02:06:36 by brpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <libft.h>
# include <mlx.h>
# include <fcntl.h>
# include <math.h>

# define WIN_HEIGHT 1080
# define WIN_WIDTH 1920
# define SPACE 50
# define ORT 0
# define ISO 1

typedef struct		s_map
{
	int				**map;
	int				row_sum;
	int				col_sum;
	int				x;
	int				y;
	int				pts_sum;
}					t_map;

typedef struct		s_cam
{
	int				margin_x;
	int				margin_y;
	int				space;
	int				proj;
	int				trans_y;
	int				trans_x;
	float			rot_x;
	float			rot_y;
	float			rot_z;
	int				val;
	int				zoom;
	int				sat;
	int				bgt;
}					t_cam;

typedef struct		s_point
{
	int				x;
	int				y;
	int				sx;
	int				sy;
	int				err;
	int				z;
	int				e2;
}					t_point;

typedef struct		s_img
{
	void			*img_ptr;
	unsigned char	*data;
	int				size_l;
	int				bpp;
	int				endian;
}					t_img;

typedef struct		s_env
{
	void			*dis;
	void			*win;
	int				win_width;
	int				win_height;
	struct s_map	map;
	struct s_img	img;
	struct s_cam	cam;
	struct s_point	start;
	struct s_point	current;
	struct s_point	end;
	struct s_point	delta;
}					t_env;

int					fdf(int fd);
void				init_env(t_env *env);
int					ft_key_press(int key, t_env *env);
t_list				*check_file(int fd);
int					init_map(t_env *env, int fd);
int					ft_close(void *param);
void				ft_create_img(t_env *env);
int					init_img(t_env *env);
void				ft_bresenham(t_env *env);
void				ft_iso(int *x, int *y, int z);
void				ft_rot_x(t_env *env, int *y, int *z);
void				ft_rot_y(t_env *env, int *x, int *z);
void				ft_rot_z(t_env *env, int *x, int *y);
void				origin_point(t_env *env);
void				next_point_line(t_env *env);
void				next_point_col(t_env *env);
void				get_color(t_env *env, int height, int pixel);
int					ft_close(void *param);
#endif
