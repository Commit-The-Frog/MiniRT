/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjacho <minjacho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 19:53:00 by minjacho          #+#    #+#             */
/*   Updated: 2024/05/24 19:51:36 by minjacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "hit.h"

// t값을 바탕으로 법선과 접점 구하기
t_hit hit_coord_cal_sp(t_vec *ray, t_coord *cam, t_obj *obj, t_hit *hit)
{
	hit->point = get_coord_by_t(ray, hit->t, cam);
	hit->vec = vsub(coord_to_vec(hit->point), coord_to_vec(*(obj->coord)));
	if (vdot(hit->vec, *ray) > 0)
	{
		hit->vec.x *= -1;
		hit->vec.y *= -1;
		hit->vec.z *= -1;
	}
	norm(&(hit->vec));
	return (*hit);
}

// 접점 p = e + td (여기서 d는 단위벡터 e는 원점의 값)
// t^2 + 2(d*ce)t + ||ce||^2 = r^2
// a = 1, b = d * ce, c = ce^2 - r^2
t_hit hit_sp(t_vec *ray, t_coord *cam, t_obj *obj, t_hit *hit)
{
	t_vec	centerv;
	t_vec	camv;
	double	b;
	double	c;

	centerv = coord_to_vec(*(obj->coord));
	camv = coord_to_vec(*cam);
	b = vdot(*ray, vsub(camv, centerv));
	c = vsizesq(vsub(camv, centerv)) - pow(obj->dia / 2, 2);
	if (evendet(vsizesq(*ray), b, c) <= 1e-6)
		hit->hitted = 0;
	else
	{
		hit->hitted = 1;
		if (solve_neg(vsizesq(*ray), b, c) > 0)
			hit->t = solve_neg(vsizesq(*ray), b, c);
		else if (solve_pos(vsizesq(*ray), b, c) > 0)
			hit->t = solve_pos(vsizesq(*ray), b, c);
		else
			hit->hitted = 0;
	}
	hit->obj_color = *(obj->color);
	return (hit_coord_cal_sp(ray, cam, obj, hit));
}

t_hit hit_pl(t_vec *ray, t_coord *cam, t_obj *obj, t_hit *hit)
{
	t_vec	pl_dotv;
	t_vec	camv;

	pl_dotv = coord_to_vec(*(obj->coord));
	camv = coord_to_vec(*cam);
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
		hit->point = get_coord_by_t(ray, hit->t, cam);
		hit->vec = *(obj->vec);
		norm(&(hit->vec));
		if (vdot(hit->vec, *ray) > 0)
		{
			hit->vec.x *= -1;
			hit->vec.y *= -1;
			hit->vec.z *= -1;
		}
	}
	hit->obj_color = *(obj->color);
	return (*hit);
}

// t_hit hit_cy(t_vec *ray, t_coord *cam, t_obj *obj, t_hit *hit)
// {
// 	hit->hitted = 0;
// 	return (*hit);
// }
