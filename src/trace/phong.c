/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:01:16 by junkim2           #+#    #+#             */
/*   Updated: 2024/05/27 18:21:38 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// Specular
// (기존 색) * (spec 색) / 255 * (spec ratio)
t_color	specular(t_vec ray, t_hit hit, t_light light)
{
	t_color	res;
	t_color	light_color;
	t_vec	l;
	t_vec	r;
	double	angle;

	init_color(0, 0, 0, &res);
	l = coord2_to_vec(light.coord, hit.point);
	norm(&hit.vec);
	norm(&l);
	r = vsum(l, vsmul(hit.vec, vdot(vsmul(l, -1), hit.vec) * 2));
	angle = pow(max(vdot(r, vsmul(ray, -1)), 0), 3);
	light_color = csdiv(light.color, 255);
	res = csmul(csmul(cmul(hit.obj_color, light_color), light.ratio), angle);
	return (res);
}

// Diffuse
// (기존 색) * (dif 색) / 255 * (dif ratio)
t_color	diffuse(t_hit hit, t_light light)
{
	t_color	res;
	t_color	light_color;
	t_vec	l;
	t_vec	n;
	double	angle;

	init_color(0, 0, 0, &res);
	n = hit.vec;
	l = coord2_to_vec(hit.point, light.coord);
	norm(&n);
	norm(&l);
	angle = max(vdot(n, l), 0);
	light_color = csdiv(light.color, 255);
	res = csmul(csmul(cmul(hit.obj_color, light_color), light.ratio), angle);
	return (res);
}

// Ambient
// (기존 색) * (amb 색) / 255 * (amb ratio)
t_color	ambient(t_color obj_color, t_light amb)
{
	t_color	res;

	init_color(0, 0, 0, &res);
	res = csum(res, cmul(csmul(csdiv(amb.color, 255), amb.ratio), obj_color));
	return (res);
}

int	obj_hit_iter(t_list *olist, t_list *llist, t_hit hit)
{
	t_list	*cur;
	int		flag;

	cur = olist;
	flag = 0;
	while (cur)
	{
		if (is_hitted(((t_light *)llist->content)->coord, hit.point, \
			(t_obj *)cur->content, hit.my))
		{
			flag = 1;
			return (flag);
		}
		cur = cur->next;
	}
	return (flag);
}

// trace ray from object to light
// calculate amount of light to ratio(0-1),
// returns color value (unsigned int)
unsigned long	phong(t_vec ray, t_hit hit, t_dim dim)
{
	t_color	res;
	t_list	*llist;

	if (!hit.hitted)
		return (0x00);
	init_color(0, 0, 0, &res);
	res = csum(res, ambient(hit.obj_color, dim.amb));
	llist = dim.llist;
	while (llist)
	{
		if (!obj_hit_iter(dim.olist, llist, hit))
		{
			res = csum(res, diffuse(hit, *(t_light *)llist->content));
			res = csum(res, specular(ray, hit, *(t_light *)llist->content));
		}
		llist = llist->next;
	}
	return (rgb_to_hex(res));
}
