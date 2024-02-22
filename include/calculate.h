#ifndef CALCULATE_H
# define CALCULATE_H

# include "minirt.h"

void	cal_main(t_dimension *dimension);

void	cross_product(t_vector *v1, t_vector *v2, t_vector *res);
double	dot_product(t_vector *v1, t_vector *v2);
void	vector_print(t_vector v);

#endif
