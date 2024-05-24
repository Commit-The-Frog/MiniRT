/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjacho <minjacho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 20:52:17 by minjacho          #+#    #+#             */
/*   Updated: 2024/05/22 22:01:18 by minjacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "raytrace.h"

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

t_vec	coord_to_vec(t_coord c, t_vec vec)
{
	vec.x = c.x;
	vec.y = c.y;
	vec.z = c.z;
	return (vec);
}

t_vec	vsub(t_vec v1, t_vec v2)
{
	v1.x -= v2.x;
	v1.y -= v2.y;
	v1.z -= v2.z;
	return (v1);
}

double	vdot(t_vec v1, t_vec v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

double vlen(t_vec v)
{
	return (sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2)));
}

double vlensq(t_vec v)
{
	return (pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2));
}
