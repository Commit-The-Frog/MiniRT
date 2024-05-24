/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjacho <minjacho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 20:31:23 by minjacho          #+#    #+#             */
/*   Updated: 2024/05/24 17:18:12 by minjacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "hit.h"

unsigned long	get_color(t_hit *hit, t_list *llist, t_light *amb)
{
	(void)llist;
	(void)amb;
	if (hit->hitted)
	{
		return (rgb_to_hex(&hit->obj_color));
	}
	else
		return (0x00);
}

t_hit	hit_obj(t_vec *ray, t_coord *cam, t_obj *obj, t_hit *hit)
{
	if (obj->type == SP)
		return (hit_sp(ray, cam, obj, hit));
	else if (obj->type == PL)
		return (hit_pl(ray, cam, obj, hit));
	else if (obj->type == CY)
		return (hit_pl(ray, cam, obj, hit));
	else
		return (*hit);
}

//ray가 obj배열들을 체크하여 부딪히는 점이 있는지 확인.
// 있으면 hitted를 1로 하여 접점과 법선 벡터를 리턴.
t_hit	hit_obj_iter(t_vec *ray, t_coord *cam, t_list *olist, t_hit *hit)
{
	t_hit	new_hit;
	t_list	*p;

	new_hit.hitted = 0;
	p = olist;
	while (p)
	{
		new_hit = hit_obj(ray, cam, p->content, &new_hit);
		if (new_hit.hitted && (hit->hitted == 0 || hit->t > new_hit.t))
			*hit = new_hit;
		p = p->next;
	}
	return (*hit);
}

unsigned long	raytrace(t_vec *ray, t_dim *dim)
{
	t_hit hit;
	hit.hitted = 0;
	hit = hit_obj_iter(ray, dim->cam_coord, dim->olist, &hit);
	return (get_color(&hit, dim->llist, dim->amb));
}
