#ifndef CALCULATE_H
# define CALCULATE_H

# include "minirt.h"

/* init_dim.c */
void	cal_main(t_dim *dim, t_info *info);

/* cal_util.c */
void	vector_print(t_vec v);
void	coord_print(t_coord coord);
void	matrix_print_4(double matrix[][4]);

#endif
