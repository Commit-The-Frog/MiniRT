/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:58:48 by junkim2           #+#    #+#             */
/*   Updated: 2024/05/27 17:58:49 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// sum of vector v1 + v2
t_vec	vsum(t_vec v1, t_vec v2)
{
	v1.x += v2.x;
	v1.y += v2.y;
	v1.z += v2.z;
	return (v1);
}

double	coord_dist(const t_coord c1, const t_coord c2)
{
	double	x;
	double	y;
	double	z;

	x = pow(c1.x - c2.x, 2);
	y = pow(c1.y - c2.y, 2);
	z = pow(c1.z - c2.z, 2);
	return (sqrt(x + y + z));
}

t_vec	coord_to_vec(t_coord c)
{
	t_vec	vec;

	vec.x = c.x;
	vec.y = c.y;
	vec.z = c.z;
	return (vec);
}

double	vsizesq(t_vec v)
{
	return (pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2));
}

// make two coord to vector v = c2 - c1;
t_vec	coord2_to_vec(t_coord c1, t_coord c2)
{
	t_vec	res;

	res.x = c2.x - c1.x;
	res.y = c2.y - c1.y;
	res.z = c2.z - c1.z;
	return (res);
}

// double	vsize(t_vec v)
// {
// 	return (sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2)));
// }

// scalar sum of vector v1 + sc
// t_vec	vssum(t_vec v1, double sc)
// {
// 	v1.x += sc;
// 	v1.y += sc;
// 	v1.z += sc;
// 	return (v1);
// }
