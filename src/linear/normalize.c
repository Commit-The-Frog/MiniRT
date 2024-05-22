/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:52:25 by minjacho          #+#    #+#             */
/*   Updated: 2024/05/22 16:21:47 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linear.h"

void	normalize(t_vec *vec)
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
