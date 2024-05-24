/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjacho <minjacho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 19:53:00 by minjacho          #+#    #+#             */
/*   Updated: 2024/05/24 17:12:43 by minjacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "hit.h"

// 접점 p = e + td (여기서 d는 단위벡터 e는 원점의 값)
// t^2 + 2(d*ce)t + ||ce||^2 = r^2
// a = 1, b = d * ce, c = ce^2 - r^2
t_hit hit_sp(t_vec *ray, t_coord *cam, t_obj *obj, t_hit *hit)
{
	t_vec	centerv;
	t_vec	camv;
	double	b;
	double	c;
	double	det;

	centerv = coord_to_vec(*(obj->coord));
	camv = coord_to_vec(*cam);
	b = vdot(*ray, vsub(camv, centerv));
	c = vsizesq(vsub(camv, centerv)) - pow(obj->dia / 2, 2);
	det = pow(b, 2) - c * vsizesq(*ray);
	if (det <= 1e-6)
		hit->hitted = 0;
	else
	{
		hit->hitted = 1;
	} // hit->t 값도 추가해야됨.
	hit->obj_color = *(obj->color);
	return (*hit);
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
		hit->hitted = 1;
	hit->obj_color = *(obj->color);
	return (*hit);
}

// t_hit hit_cy(t_vec *ray, t_coord *cam, t_obj *obj, t_hit *hit)
// {
// 	hit->hitted = 0;
// 	return (*hit);
// }
