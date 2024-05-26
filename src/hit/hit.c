/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjacho <minjacho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 19:53:00 by minjacho          #+#    #+#             */
/*   Updated: 2024/05/26 14:20:49 by minjacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "hit.h"

// t값을 바탕으로 hit의 vec, point, obj_color 설정
t_hit hit_coord_cal_sp(t_vec *ray, t_coord cam, t_obj *obj, t_hit *hit)
{
	hit->point = get_coord_by_t(ray, hit->t, cam);
	hit->vec = vsub(coord_to_vec(hit->point), coord_to_vec(*(obj->coord)));
	if (vdot(hit->vec, *ray) > 0)
		hit->vec = vrev(hit->vec);
	norm(&(hit->vec));
	hit->obj_color = *(obj->color);
	return (*hit);
}

// t값을 바탕으로 hit의 vec, point, obj_color 설정
t_hit hit_coord_cal_pl(t_vec *ray, t_coord cam, t_obj *obj, t_hit *hit)
{
	hit->point = get_coord_by_t(ray, hit->t, cam);
	hit->vec = *(obj->vec);
	norm(&(hit->vec));
	if (vdot(hit->vec, *ray) > 0)
		hit->vec = vrev(hit->vec);
	hit->obj_color = *(obj->color);
	return (*hit);
}

// t값을 바탕으로 hit의 vec, point, obj_color 설정
t_hit hit_coord_cal_cy(t_vec *ray, t_coord cam, t_obj *obj, t_hit *hit)
{
	t_vec	cp;

	hit->point = get_coord_by_t(ray, hit->t, cam);
	cp = coord2_to_vec(get_coord_by_t(obj->vec, -1 * (obj->height / 2), *obj->coord), hit->point);
	hit->vec = vsub(cp, vsmul(*obj->vec, vdot(cp, *obj->vec)));
	norm(&(hit->vec));
	if (vdot(hit->vec, *ray) > 0)
		hit->vec = vrev(hit->vec);
	hit->obj_color = *(obj->color);
	return (*hit);
}

// 접점 p = e + td (여기서 d는 단위벡터 e는 원점의 값)
// t^2 + 2(d*ce)t + ||ce||^2 = r^2
// a = 1, b = d * ce, c = ce^2 - r^2
// hit이 되었는지 확인하여서, t_hit의 t, hitted 설정
t_hit hit_sp(t_vec *ray, t_coord cam, t_obj *obj, t_hit *hit)
{
	t_vec	centerv;
	t_vec	camv;
	t_solve	res;

	centerv = coord_to_vec(*(obj->coord));
	camv = coord_to_vec(cam);
	res = solve_with_det(vsizesq(*ray), vdot(*ray, vsub(camv, centerv)), \
		vsizesq(vsub(camv, centerv)) - pow(obj->dia / 2 + hit->bias, 2));
	if (res.det <= 1e-6)
		hit->hitted = 0;
	else
	{
		hit->hitted = 1;
		hit->my = obj;
		if (res.neg_x > 0)
			hit->t = res.neg_x;
		else if (res.pos_x > 0)
			hit->t = res.pos_x;
		else
			hit->hitted = 0;
	}
	return (*hit);
}

// hit이 되었는지 확인하여서, t_hit의 t, hitted 설정
t_hit hit_pl(t_vec *ray, t_coord cam, t_obj *obj, t_hit *hit)
{
	t_vec	pl_dotv;
	t_vec	camv;

	pl_dotv = coord_to_vec(*(obj->coord));
	camv = coord_to_vec(cam);
	hit->hitted = 0;
	norm(obj->vec);
	norm(ray);
	hit->t = vdot(vsub(pl_dotv, camv), *(obj->vec)) / \
	vdot(*ray, *(obj->vec));
	if (hit->t < 1e-6)
		hit->hitted = 0;
	else
	{
		hit->hitted = 1;
		hit->my = obj;
	}
	return (*hit);
}

t_hit	hit_cy_pl_up(t_vec *ray, t_coord cam, t_obj *obj, t_hit *hit)
{
	t_vec	pl_dotv;
	t_vec	camv;
	t_coord	up_coord;

	up_coord = get_coord_by_t(obj->vec, -1 * (obj->height / 2), *obj->coord);
	pl_dotv = coord_to_vec(up_coord);
	camv = coord_to_vec(cam);
	hit->hitted = 0;
	norm(obj->vec);
	norm(ray);
	hit->t = vdot(vsub(pl_dotv, camv), *(obj->vec)) / \
	vdot(*ray, *(obj->vec));
	if (hit->t < 1e-6)
		hit->hitted = 0;
	else
	{
		hit->hitted = 1;
		hit->my = obj;
		*hit = hit_coord_cal_pl(ray, cam, obj, hit);
		if (coord_dist(hit->point, up_coord) >= obj->dia / 2)
			hit->hitted = 0;
	}
	return (*hit);
}

t_hit	hit_cy_pl_down(t_vec *ray, t_coord cam, t_obj *obj, t_hit *hit)
{
	t_vec	pl_dotv;
	t_vec	camv;
	t_coord	down_coord;

	down_coord = get_coord_by_t(obj->vec, obj->height / 2, *obj->coord);
	pl_dotv = coord_to_vec(down_coord);
	camv = coord_to_vec(cam);
	hit->hitted = 0;
	norm(obj->vec);
	norm(ray);
	hit->t = vdot(vsub(pl_dotv, camv), *(obj->vec)) / \
	vdot(*ray, *(obj->vec));
	if (hit->t < 1e-6)
		hit->hitted = 0;
	else
	{
		hit->hitted = 1;
		hit->my = obj;
		*hit = hit_coord_cal_pl(ray, cam, obj, hit);
		if (coord_dist(hit->point, down_coord) >= obj->dia / 2)
			hit->hitted = 0;
	}
	return (*hit);
}

t_hit hit_cy(t_vec *ray, t_coord cam, t_obj *obj, t_hit *hit)
{
	t_hit	up;
	t_hit	down;
	t_hit	plain;
	t_solve	res;
	t_vec	ce;

	norm(obj->vec);
	ce = coord2_to_vec(get_coord_by_t(obj->vec, -1 * (obj->height / 2), *obj->coord), cam);
	up = hit_cy_pl_up(ray, cam, obj, &up);
	down = hit_cy_pl_down(ray, cam, obj, &down);
	if (up.hitted && down.hitted)
	{
		if (up.t < down.t)
			plain = up;
		else
			plain = down;
	}
	else if (up.hitted)
		plain = up;
	else
		plain = down;
	res = solve_with_det(pow(vdot(*obj->vec, *ray), 2) - 1, \
		vdot(*obj->vec, *ray) * vdot(ce, *obj->vec) - vdot(ce, *ray), \
		pow(obj->dia / 2 + hit->bias, 2) - vdot(ce, ce) + pow(vdot(ce, *obj->vec), 2));
	if (res.det <= 0)
		hit->hitted = 0;
	else
	{
		hit->hitted = 1;
		hit->my = obj;
		if (res.pos_x > 0)
			hit->t = res.pos_x;
		else if (res.neg_x > 0)
			hit->t = res.neg_x;
		else
			hit->hitted = 0;
	}
	if (hit->hitted)
	{
		*hit = hit_coord_cal_cy(ray, cam, obj, hit);
		if (fabs(vdot(coord2_to_vec(hit->point, *obj->coord), *obj->vec)) >= obj->height / 2)
			hit->hitted = 0;
	}
	if (plain.hitted)
	{
		if (!hit->hitted || plain.t < hit->t)
			*hit = plain;
	}
	return (*hit);
}

//두 점이 주어졌을때, obj와 부딪히는 부분이 두 점 사이에 있는지 확인한다.
int	is_hitted(t_coord start, t_coord end, t_obj *obj, t_obj *my)
{
	t_hit	res;
	t_vec	vec;
	double	end_t;

	if (obj == my)
		return (0);
	vec = vsub(coord_to_vec(end), coord_to_vec(start));
	norm(&vec);
	end_t = get_t_by_coord(vec, start, end);
	if (obj->type == SP)
	{
		res.bias = 0.00001;
		res = hit_sp(&vec, start, obj, &res);
		if (res.hitted && (res.t > 0 && res.t < end_t))
			return (1);
	}
	else if (obj->type == PL)
	{
		res.bias = 0.00001;
		res = hit_pl(&vec, start, obj, &res);
		if (res.hitted && (res.t > 0 && res.t < end_t))
			return (1);
	}
	else if (obj->type == CY)
	{
		res.bias = 0.00001;
		res = hit_cy(&vec, start, obj, &res);
		if (res.hitted && (res.t > 0 && res.t < end_t))
			return (1);
	}
	return (0);
}
