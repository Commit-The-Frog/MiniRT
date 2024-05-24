/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjacho <minjacho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 19:39:12 by junkim2           #+#    #+#             */
/*   Updated: 2024/05/24 17:15:20 by minjacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// convert coordinate(x,y,z) to t_vec
void	init_vec(double x, double y, double z, t_vec *vec)
{
	vec->x = x;
	vec->y = y;
	vec->z = z;
}

// copy vector "src" to "dest"
void	copy_vec(t_vec *dest, t_vec src)
{
	dest->x = src.x;
	dest->y = src.y;
	dest->z = src.z;
}

/* check if v1 and v2 vector is same
   (v1.x == v2.x && v1.y == v2.y && v1.z == v2.z) */
int	comp_vec(t_vec v1, t_vec v2)
{
	if (v1.x == v2.x && v1.y == v2.y && v1.z == v2.z)
		return 1;
	return (0);
}

// vector substraction v1 - v2 and result saved in res
t_vec	vsub(t_vec v1, t_vec v2)
{
	v1.x -= v2.x;
	v1.y -= v2.y;
	v1.z -= v2.z;
	return (v1);
}

// scalar multiply of vector v1 * sc
t_vec	vsmul(t_vec v1, double sc)
{
	v1.x *= sc;
	v1.y *= sc;
	v1.z *= sc;
	return (v1);
}

// sum of vector v1 + v2
t_vec	vsum(t_vec v1, t_vec v2)
{
	v1.x += v2.x;
	v1.y += v2.y;
	v1.z += v2.z;
	return (v1);
}

double coord_dist(const t_coord c1, const t_coord c2)
{
	double x;
	double y;
	double z;

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

double vsize(t_vec v)
{
	return (sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2)));
}

double vsizesq(t_vec v)
{
	return (pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2));
}
