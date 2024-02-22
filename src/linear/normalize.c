/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjacho <minjacho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:52:25 by minjacho          #+#    #+#             */
/*   Updated: 2024/02/22 21:13:40 by minjacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linear.h"

void	normalize(t_vector *vec)
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