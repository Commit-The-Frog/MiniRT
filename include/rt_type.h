#ifndef RT_TYPE_H
# define RT_TYPE_H

# include "libft.h"

typedef enum e_type
{
	AMBIENT_LIGHT,
	CAMERA,
	LIGHT,
	SPHERE,
	PLANE,
	CYLINDER
}	t_type;

typedef struct s_coord
{
	double	x;
	double	y;
	double	z;
}	t_coord;

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
	t_type		type;
	t_coord		*coord;
	t_vector	*vec;
	double		dia;
	double		height;
	t_color		*color;
}	t_obj;

typedef struct s_light
{
	t_type	type;
	t_coord	*coord;
	double	bright_ratio;
	t_color	*color;
}	t_light;

typedef struct s_dimension
{
	t_coord		*cam_coord;		// essential
	t_vector	*cam_vector;	// essential
	double		cam_fov;		// essential
	t_light		*ambient;		// essential
	t_list		*light_list;
	t_list		*obj_list;
}	t_dimension;

typedef struct s_info
{
	int		argc;
	char	**argv;
	int		fd;
}	t_info;

#endif
