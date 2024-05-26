/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjacho <minjacho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 19:00:28 by minjacho          #+#    #+#             */
/*   Updated: 2024/05/26 19:00:57 by minjacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit.h"

t_solve	solve_with_det(double a, double b, double c)
{
	t_solve	res;

	res.det = evendet(a, b, c);
	if (res.det > 0)
	{
		res.neg_x = solve_neg(a, b, c);
		res.pos_x = solve_pos(a, b, c);
	}
	return (res);
}

double	evendet(double a, double b, double c)
{
	return (pow(b, 2) - c * a);
}

double	solve_pos(double a, double b, double c)
{
	double	upper;
	double	lower;

	upper = -b + sqrt(pow(b, 2) - a * c);
	lower = a;
	return (upper / lower);
}

double	solve_neg(double a, double b, double c)
{
	double	upper;
	double	lower;

	upper = -b - sqrt(pow(b, 2) - a * c);
	lower = a;
	return (upper / lower);
}
