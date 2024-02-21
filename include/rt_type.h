#ifndef RT_TYPE_H
# define RT_TYPE_H

# include "libft.h"

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
}	t_point;

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}	t_vector;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_obj
{
	int			type;
	t_point		point;
	t_vector	vec;
	double		dia;
	double		height;
	t_color		color;
}	t_obj;

typedef struct s_light
{
	int		type;
	t_point	point;
	double	bright_ratio;
	t_color	color;
}	t_light;

typedef struct s_dimension
{
	t_point		cam_point;
	t_vector	cam_vector;
	double		cam_fov;
	t_light		ambient;
	t_list		light_list;
	t_list		obj_list;
}	t_dimension;

#endif
