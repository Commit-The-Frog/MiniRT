/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   product.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:24:24 by minjacho          #+#    #+#             */
/*   Updated: 2024/05/22 16:21:38 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	cross_product(t_vec *v1, t_vec *v2, t_vec *res)
{
	res->x = v1->y * v2->z - v1->z * v2->y;
	res->y = v1->z * v2->x - v1->x * v2->z;
	res->z = v1->x * v2->y - v1->y * v2->x;
}

double	dot_product(t_vec *v1, t_vec *v2)
{
	double	res;

	res = 0;
	res += v1->x * v2->x;
	res += v1->y * v2->y;
	res += v1->z * v2->z;
	return (res);
}

