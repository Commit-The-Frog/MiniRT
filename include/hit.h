#ifndef HIT_H
# define HIT_H

# include "minirt.h"

t_hit hit_sp(t_vec *ray, t_coord *cam, t_obj *obj, t_hit *hit);
t_hit hit_pl(t_vec *ray, t_coord *cam, t_obj *obj, t_hit *hit);
t_hit hit_cy(t_vec *ray, t_coord *cam, t_obj *obj, t_hit *hit);

// raytrace 진행. ray로 각 픽셀마다의 ray를 넘겨받음.
unsigned long	raytrace(t_vec *ray, t_dim *dim);

// unsigned long	get_color(t_vec *ray, t_hit *hit, t_list *llist, t_light *amb);

#endif
