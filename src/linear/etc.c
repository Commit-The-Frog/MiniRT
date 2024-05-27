/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:52:25 by minjacho          #+#    #+#             */
/*   Updated: 2024/05/25 14:25:58 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linear.h"

// return max of value v1, v2
double	max(double v1, double v2)
{
	if (v1 >= v2)
		return (v1);
	else
		return (v2);
}

// return min of value v1, v2
double	min(double v1, double v2)
{
	if (v1 <= v2)
		return (v1);
	else
		return (v2);
}

// normalize vector
void	norm(t_vec *vec)
{
	double	size;

	size = pow(vec->x, 2) + pow(vec->y, 2) + pow(vec->z, 2);
	size = sqrt(size);
	if (!size)
		return ;
	vec->x /= size;
	vec->y /= size;
	vec->z /= size;
}
