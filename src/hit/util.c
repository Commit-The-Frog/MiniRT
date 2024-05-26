/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 18:36:59 by minjacho          #+#    #+#             */
/*   Updated: 2024/05/26 17:47:55 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit.h"

t_solve	solve_with_det(double a, double b, double c)
{
	t_solve	res;

	res.det = evendet(a, b, c);
	if (res.det > 0)
	{
		res.neg_x = solve_neg(a, b, c);
		res.pos_x = solve_pos(a, b, c);
	}
	return (res);
}

double	evendet(double a, double b, double c)
{
	return (pow(b,2) - c * a);
}

double	solve_pos(double a, double b, double c)
{
	double	upper;
	double	lower;

	upper = - b + sqrt(pow(b, 2) - a * c);
	lower = a;
	return (upper/lower);
}

double	solve_neg(double a, double b, double c)
{
	double	upper;
	double	lower;

	upper = - b - sqrt(pow(b, 2) - a * c);
	lower = a;
	return (upper/lower);
}

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
	return (coord.x - start.x) / vec.x;
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
