/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiplier.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjacho <minjacho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 20:37:56 by minjacho          #+#    #+#             */
/*   Updated: 2024/02/22 21:53:18 by minjacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	maxtrix_mul_4_by_4(double m1[][4], double m2[][4], double result[][4])
{
	int	i;
	int	j;
	int	k;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			result[i][j] = 0;
	}
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			k = -1;
			while (++k < 4)
				result[i][j] += m1[i][k] * m2[k][j];
		}
	}
}
