#ifndef CALCULATE_H
# define CALCULATE_H

# include "minirt.h"

typedef struct s_screen
{
	double	gx;
	double	gy;
	t_vec	dx;
	t_vec	dy;
	int		i;
	int		j;
	t_vec	origin;
	t_vec	ray;
}	t_screen;

/* init_dim.c */
void	cal_main(t_dim *dim, t_info *info);

/* cal_util.c */
void	vector_print(t_vec v);
void	coord_print(t_coord coord);
void	matrix_print_4(double matrix[][4]);
void	color_print(t_color c);


#endif
