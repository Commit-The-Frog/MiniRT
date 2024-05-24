#ifndef LINEAR_H
# define LINEAR_H

# include "minirt.h"

/* product.c */
t_vec	vcross(t_vec v1, t_vec v2);
double	vdot(t_vec v1, t_vec v2);

/* normalize.c */
void	norm(t_vec *vec);

/* vector.c */
t_vec	coord_to_vec(t_coord c);
void	init_vec(double x, double y, double z, t_vec *vec);
void	copy_vec(t_vec *dest, t_vec src);
int		comp_vec(t_vec v1, t_vec v2);
t_vec	vsub(t_vec v1, t_vec v2);
t_vec	vsmul(t_vec v1, double sc);
t_vec	vsum(t_vec v1, t_vec v2);

#endif
