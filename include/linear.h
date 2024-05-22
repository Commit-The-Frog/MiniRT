#ifndef LINEAR_H
# define LINEAR_H

# include "minirt.h"

void	cross_product(t_vec *v1, t_vec *v2, t_vec *res);
double	dot_product(t_vec *v1, t_vec *v2);
void	normalize(t_vec *vec);
void	maxtrix_mul_4_by_4(double m1[][4], double m2[][4], double result[][4]);

#endif
