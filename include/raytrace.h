#ifndef RAYTRACE_H
# define RAYTRACE_H

# include "minirt.h"

typedef struct s_hit
{
	int		hitted; // hit 여부
	double	t; // p = e + td에서 t값
	t_coord	point; // 접점
	t_vec	vec; //법선 벡터
}	t_hit;

t_hit hit_sp(t_vec *ray, t_coord *cam, t_obj *obj, t_hit *hit);
t_hit hit_pl(t_vec *ray, t_coord *cam, t_obj *obj, t_hit *hit);
t_hit hit_cy(t_vec *ray, t_coord *cam, t_obj *obj, t_hit *hit);

// 두 점간의 거리 리턴
double	coord_dist(const t_coord c1, const t_coord c2);
t_vec	coord_to_vec(t_coord c, t_vec vec);
t_vec	vsub(t_vec v1, t_vec v2);
double	vdot(t_vec v1, t_vec v2);
double	vlen(t_vec v);
double	vlensq(t_vec v);

// raytrace 진행. ray로 각 픽셀마다의 ray를 넘겨받음.
t_color	*raytrace(t_vec *ray, t_dim *dim, t_color *res);

t_color	*get_color(t_hit *hit, t_light *light, t_light *amb, t_color *res);
#endif
