/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjacho <minjacho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 18:36:59 by minjacho          #+#    #+#             */
/*   Updated: 2024/05/27 11:21:04 by minjacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit.h"

t_coord	get_coord_by_t(t_vec vec, double t, t_coord coord)
{
	t_vec	coord_vec;
	t_coord	res_c;

	coord_vec = vsmul(vec, t);
	res_c.x = coord_vec.x + coord.x;
	res_c.y = coord_vec.y + coord.y;
	res_c.z = coord_vec.z + coord.z;
	return (res_c);
}

double	get_t_by_coord(t_vec vec, t_coord start, t_coord coord)
{
	return ((coord.x - start.x) / vec.x);
}

// 매개변수 값은 변하지 않는다.
t_vec	vrev(t_vec vec)
{
	t_vec	res;

	res = vec;
	res.x *= -1;
	res.y *= -1;
	res.z *= -1;
	return (res);
}

t_coord	set_bias(t_vec t, t_coord coord, double bias)
{
	if (bias == 0)
		return (coord);
	coord.x += t.x * bias;
	coord.y += t.y * bias;
	coord.z += t.z * bias;
	return (coord);
}
