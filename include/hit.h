#ifndef HIT_H
# define HIT_H

# include "minirt.h"

typedef struct	s_solve
{
	double	det;
	double	neg_x;
	double	pos_x;
}	t_solve;

t_hit hit_sp(t_vec *ray, t_coord cam, t_obj *obj, t_hit *hit);
t_hit hit_coord_cal_sp(t_vec *ray, t_coord cam, t_obj *obj, t_hit *hit);
t_hit hit_pl(t_vec *ray, t_coord cam, t_obj *obj, t_hit *hit);
t_hit hit_coord_cal_pl(t_vec *ray, t_coord cam, t_obj *obj, t_hit *hit);
t_hit	hit_cy_pl_up(t_vec *ray, t_coord cam, t_obj *obj, t_hit *hit);
t_hit	hit_cy_pl_down(t_vec *ray, t_coord cam, t_obj *obj, t_hit *hit);
t_hit hit_cy(t_vec *ray, t_coord cam, t_obj *obj, t_hit *hit);
int	is_hitted(t_coord start, t_coord end, t_obj *obj, t_obj *my);

// raytrace 진행. ray로 각 픽셀마다의 ray를 넘겨받음.
unsigned long	raytrace(t_vec *ray, t_dim *dim);

// unsigned long	get_color(t_vec *ray, t_hit *hit, t_list *llist, t_light *amb);

t_solve	solve_with_det(double a, double b, double c);
double	evendet(double a, double b, double c);
double	solve_pos(double a, double b, double c);
double	solve_neg(double a, double b, double c);
t_coord	get_coord_by_t(t_vec *vec, double t, t_coord coord);
double	get_t_by_coord(t_vec vec, t_coord start, t_coord coord);
t_vec	vrev(t_vec vec);

#endif
