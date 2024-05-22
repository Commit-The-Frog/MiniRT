#ifndef CALCULATE_H
# define CALCULATE_H

# include "minirt.h"

void	cal_main(t_dim *dim);

void	cross_product(t_vec *v1, t_vec *v2, t_vec *res);
double	dot_product(t_vec *v1, t_vec *v2);
void	vector_print(t_vec v);
void	matrix_print_4(double matrix[][4]);
#endif
