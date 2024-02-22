#ifndef LINEAR_H
# define LINEAR_H

# include "minirt.h"

void	cross_product(t_vector *v1, t_vector *v2, t_vector *res);
double	dot_product(t_vector *v1, t_vector *v2);
void	normalize(t_vector *vec);
void	maxtrix_mul_4_by_4(double **m1, double **m2, double **result);

#endif
