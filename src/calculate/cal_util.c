/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjacho <minjacho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:51:37 by minjacho          #+#    #+#             */
/*   Updated: 2024/02/22 17:32:12 by minjacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	cross_product(t_vector *v1, t_vector *v2, t_vector *res)
{
	res->x = v1->y * v2->z - v1->z * v2->y;
	res->y = v1->z * v2->x - v1->x * v2->z;
	res->z = v1->x * v2->y - v1->y * v2->x;
}

double	dot_product(t_vector *v1, t_vector *v2)
{
	double	res;

	res = 0;
	res += v1->x * v2->x;
	res += v1->y * v2->y;
	res += v1->z * v2->z;
	return (res);
}

void	vector_print(t_vector v)
{
	printf("[%lf][%lf][%lf]\n", v.x, v.y, v.z);
}
