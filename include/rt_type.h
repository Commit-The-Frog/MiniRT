/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_type.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:06:23 by junkim2           #+#    #+#             */
/*   Updated: 2024/05/27 18:07:59 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_TYPE_H
# define RT_TYPE_H

# include "libft.h"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef enum e_type
{
	AMB,
	CAM,
	L,
	SP,
	PL,
	CY
}	t_type;

typedef struct s_coord
{
	double	x;
	double	y;
	double	z;
}	t_coord;

typedef struct s_vec
{
	double	x;
	double	y;
	double	z;
}	t_vec;

typedef struct s_color
{
	double	r;
	double	g;
	double	b;
}	t_color;

typedef struct s_obj
{
	t_type		type;
	t_coord		coord;
	t_vec		vec;
	double		dia;
	double		height;
	t_color		color;
}	t_obj;

typedef struct s_light
{
	t_type	type;
	t_coord	coord;
	double	ratio;
	t_color	color;
}	t_light;

typedef struct s_dim
{
	t_coord		cam_coord;
	t_vec		cam_dir;
	t_vec		cam_xv;
	t_vec		cam_yv;
	t_vec		cam_zv;
	double		fov;
	t_light		amb;
	t_list		*llist;
	t_list		*olist;
	int			count_a;
	int			count_l;
	int			count_c;
}	t_dim;

typedef struct s_info
{
	int		argc;
	char	**argv;
	int		fd;
	void	*mlx;
	void	*mlx_win;
	t_data	img;
}	t_info;

typedef struct s_hit
{
	int		hitted;
	double	t;
	t_coord	point;
	t_vec	vec;
	t_color	obj_color;
	double	bias;
	t_obj	*my;
}	t_hit;

#endif
