/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjacho <minjacho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:51:37 by minjacho          #+#    #+#             */
/*   Updated: 2024/02/22 21:53:40 by minjacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	vector_print(t_vector v)
{
	printf("[%lf][%lf][%lf]\n", v.x, v.y, v.z);
}

void	matrix_print_4(double matrix[][4])
{
	printf("[%lf][%lf][%lf][%lf]\n", matrix[0][0], matrix[0][1], matrix[0][2], matrix[0][3]);
	printf("[%lf][%lf][%lf][%lf]\n", matrix[1][0], matrix[1][1], matrix[1][2], matrix[1][3]);
	printf("[%lf][%lf][%lf][%lf]\n", matrix[2][0], matrix[2][1], matrix[2][2], matrix[2][3]);
	printf("[%lf][%lf][%lf][%lf]\n", matrix[3][0], matrix[3][1], matrix[3][2], matrix[3][3]);
}
