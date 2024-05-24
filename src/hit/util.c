/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjacho <minjacho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 18:36:59 by minjacho          #+#    #+#             */
/*   Updated: 2024/05/24 19:17:29 by minjacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit.h"

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

t_coord	get_coord_by_t(t_vec *vec, double t, t_coord *coord)
{
	t_vec	coord_vec;
	t_coord	res_c;

	coord_vec = vsmul(*vec, t);
	res_c.x = coord_vec.x + coord->x;
	res_c.y = coord_vec.y + coord->y;
	res_c.z = coord_vec.z + coord->z;
	return (res_c);
}
