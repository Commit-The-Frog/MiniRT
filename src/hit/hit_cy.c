/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjacho <minjacho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 18:54:36 by minjacho          #+#    #+#             */
/*   Updated: 2024/05/27 17:49:17 by minjacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit.h"

t_hit	hit_cy_pl_up(t_vec ray, t_coord cam, t_obj *obj, t_hit *hit)
{
	t_vec	pl_dotv;
	t_vec	camv;
	t_coord	up_coord;

	up_coord = get_coord_by_t(obj->vec, -1 * (obj->height / 2), obj->coord);
	pl_dotv = coord_to_vec(up_coord);
	camv = coord_to_vec(cam);
	hit->hitted = 0;
	norm(&obj->vec);
	norm(&ray);
	hit->t = vdot(vsub(pl_dotv, camv), obj->vec) / \
	vdot(ray, obj->vec);
	if (hit->t < 1e-6)
		hit->hitted = 0;
	else
	{
		hit->hitted = 1;
		hit->my = obj;
		*hit = hit_coord_cal_pl(ray, cam, obj, hit);
		if (coord_dist(hit->point, \
			set_bias(obj->vec, up_coord, hit->bias * -1)) >= obj->dia / 2)
			hit->hitted = 0;
	}
	return (*hit);
}

t_hit	hit_cy_pl_down(t_vec ray, t_coord cam, t_obj *obj, t_hit *hit)
{
	t_vec	pl_dotv;
	t_vec	camv;
	t_coord	down_coord;

	down_coord = get_coord_by_t(obj->vec, obj->height / 2, obj->coord);
	pl_dotv = coord_to_vec(down_coord);
	camv = coord_to_vec(cam);
	hit->hitted = 0;
	norm(&obj->vec);
	norm(&ray);
	hit->t = vdot(vsub(pl_dotv, camv), obj->vec) / \
	vdot(ray, obj->vec);
	if (hit->t < 1e-6)
		hit->hitted = 0;
	else
	{
		hit->hitted = 1;
		hit->my = obj;
		*hit = hit_coord_cal_pl(ray, cam, obj, hit);
		if (coord_dist(hit->point, \
			set_bias(obj->vec, down_coord, hit->bias)) >= obj->dia / 2)
			hit->hitted = 0;
	}
	return (*hit);
}

t_hit	hit_cy_pl(t_vec ray, t_coord cam, t_obj *obj, t_hit *hit)
{
	t_hit	up;
	t_hit	down;

	up.bias = hit->bias;
	down.bias = hit->bias;
	up = hit_cy_pl_up(ray, cam, obj, &up);
	down = hit_cy_pl_down(ray, cam, obj, &down);
	if (up.hitted && down.hitted)
	{
		if (up.t < down.t)
			*hit = up;
		else
			*hit = down;
	}
	else if (up.hitted)
		*hit = up;
	else
		*hit = down;
	return (*hit);
}

t_hit	hit_cy_side(t_vec ray, t_coord cam, t_obj *obj, t_hit *hit)
{
	t_vec	ce;
	t_solve	res;

	ce = coord2_to_vec(get_coord_by_t(obj->vec, -1 * (obj->height / 2), \
		obj->coord), cam);
	res = solve_with_det(pow(vdot(obj->vec, ray), 2) - 1, \
		vdot(obj->vec, ray) * vdot(ce, obj->vec) - vdot(ce, ray), \
		pow(obj->dia / 2, 2) - \
		vdot(ce, ce) + pow(vdot(ce, obj->vec), 2));
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
	return (*hit);
}

t_hit	hit_cy(t_vec ray, t_coord cam, t_obj *obj, t_hit *hit)
{
	t_hit	plain;

	norm(&obj->vec);
	*hit = hit_cy_side(ray, cam, obj, hit);
	if (hit->hitted)
	{
		*hit = hit_coord_cal_cy(ray, cam, obj, hit);
		if (fabs(vdot(coord2_to_vec(hit->point, obj->coord), \
			obj->vec)) >= obj->height / 2)
			hit->hitted = 0;
	}
	plain.bias = hit->bias;
	plain = hit_cy_pl(ray, cam, obj, &plain);
	if (plain.hitted)
	{
		if (!hit->hitted || \
			coord_dist(cam, plain.point) < coord_dist(cam, hit->point))
			*hit = plain;
	}
	return (*hit);
}
