/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_shadow.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjacho <minjacho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 18:57:12 by minjacho          #+#    #+#             */
/*   Updated: 2024/05/26 18:59:24 by minjacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit.h"

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
	res.bias = 0.00001;
	res.hitted = 0;
	if (obj->type == SP)
		res = hit_sp(vec, start, obj, &res);
	else if (obj->type == PL)
		res = hit_pl(vec, start, obj, &res);
	else if (obj->type == CY)
		res = hit_cy(vec, start, obj, &res);
	return (res.hitted && (res.t > 0 && res.t < end_t));
}
