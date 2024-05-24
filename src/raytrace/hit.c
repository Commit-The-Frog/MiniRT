/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjacho <minjacho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 19:53:00 by minjacho          #+#    #+#             */
/*   Updated: 2024/05/24 12:40:01 by minjacho         ###   ########.fr       */
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

	centerv = coord_to_vec(*cam, centerv);
	camv = coord_to_vec(*cam, camv);
	b = vdot(*ray, vsub(camv, centerv));
	c = vlensq(vsub(camv, centerv)) - pow(obj->dia / 2, 2);
	if (pow(b, 2) - c > 0)
		hit->hitted = 1;
	else
		hit->hitted = 0;
	return (*hit);
}

t_hit hit_pl(t_vec *ray, t_coord *cam, t_obj *obj, t_hit *hit)
{
	hit->hitted = 0;
	return (*hit);
}

t_hit hit_cy(t_vec *ray, t_coord *cam, t_obj *obj, t_hit *hit)
{
	hit->hitted = 0;
	return (*hit);
}
