#ifndef LINEAR_H
# define LINEAR_H

# include "minirt.h"

/* product.c */
t_vec	vcross(t_vec v1, t_vec v2);
double	vdot(t_vec v1, t_vec v2);

/* etc.c */
double	min(double v1, double v2);
void	norm(t_vec *vec);

/* vector.c */
t_vec	coord_to_vec(t_coord c);
double	coord_dist(const t_coord c1, const t_coord c2);
void	init_vec(double x, double y, double z, t_vec *vec);
void	copy_vec(t_vec *dest, t_vec src);
int		comp_vec(t_vec v1, t_vec v2);
t_vec	vsub(t_vec v1, t_vec v2);
t_vec	vsmul(t_vec v1, double sc);
t_vec	vsum(t_vec v1, t_vec v2);
double	vsize(t_vec v);
double	vsizesq(t_vec v);
t_vec	vssum(t_vec v1, double sc);

/* color.c */
void	init_color(int r, int g, int b, t_color *color);
t_color	csum(t_color c1, t_color c2);
t_color	csmul(t_color c1, double sc);
t_color	cmul(t_color c1, t_color c2);
t_color	csdiv(t_color c1, double sc);

#endif
