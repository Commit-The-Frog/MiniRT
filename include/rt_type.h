#ifndef RT_TYPE_H
# define RT_TYPE_H

# include "libft.h"

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
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_obj
{
	t_type		type;
	t_coord		*coord;
	t_vec		*vec;
	double		dia;
	double		height;
	t_color		*color;
}	t_obj;

typedef struct s_light
{
	t_type	type;
	t_coord	*coord;
	double	ratio;
	t_color	*color;
}	t_light;

typedef struct s_dim
{
	t_coord		*cam_coord;		// camera coordinate
	t_vec		*cam_dir;	// camera direction
	t_vec		*cam_xv;
	t_vec		*cam_yv;
	t_vec		*cam_zv;
	double		fov;		// fov
	t_light		*amb;		// ambient light
	t_list		*llist;		// light list
	t_list		*olist;		// object list
}	t_dim;

typedef struct s_info
{
	int		argc;
	char	**argv;
	int		fd;
}	t_info;

#endif
