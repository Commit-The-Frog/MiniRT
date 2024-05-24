/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjacho <minjacho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 19:53:00 by minjacho          #+#    #+#             */
/*   Updated: 2024/05/24 14:37:47 by minjacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "raytrace.h"

// 접점 p = e + td (여기서 d는 단위벡터 e는 원점의 값)
// t^2 + 2(d*ce)t + ||ce||^2 = r^2
// a = 1, b = d * ce, c = ce^2 - r^2
t_hit hit_sp(t_vec *ray, t_coord *cam, t_obj *obj, t_hit *hit)
{
	t_vec	centerv;
	t_vec	camv;
	double	b;
	double	c;

	centerv = coord_to_vec(*(obj->coord), centerv);
	camv = coord_to_vec(*cam, camv);
	b = vdot(*ray, vsub(camv, centerv));
	c = vlensq(vsub(camv, centerv)) - pow(obj->dia / 2, 2);
	hit->t = pow(b, 2) - c * vlensq(*ray);
	if (hit->t > 0)
		hit->hitted = 1;
	else
		hit->hitted = 0;
	hit->obj_color = *(obj->color);
	return (*hit);
}

t_hit hit_pl(t_vec *ray, t_coord *cam, t_obj *obj, t_hit *hit)
{
	t_vec	pl_dotv;
	t_vec	camv;

	pl_dotv = coord_to_vec(*(obj->coord), pl_dotv);
	camv = coord_to_vec(*cam, camv);
	hit->hitted = 0;
	normalize(obj->vec);
	normalize(ray);
	hit->t = vdot(vsub(pl_dotv, camv), *(obj->vec)) / \
	vdot(*ray, *(obj->vec));
	if (hit->t < 1e-6)
		hit->hitted = 0;
	else
		hit->hitted = 1;
	hit->obj_color = *(obj->color);
	return (*hit);
}

t_hit hit_cy(t_vec *ray, t_coord *cam, t_obj *obj, t_hit *hit)
{
	hit->hitted = 0;
	return (*hit);
}
