/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjacho <minjacho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:02:39 by minjacho          #+#    #+#             */
/*   Updated: 2024/02/22 18:03:10 by minjacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// void	shoot_ray(t_dimension *dimension, t_vector *vec)
// {

// }

void	get_cam_vec(t_dimension *dimension)
{
	t_vector	v2;

	v2.x = 0;
	v2.y = 0;
	v2.z = 1;
	// have to handle the case when vector is 0,0,1
	dimension->cam_x_vec = malloc(sizeof(t_vector));
	if (!dimension->cam_x_vec)
	dimension->cam_y_vec = malloc(sizeof(t_vector));
	if (!dimension->cam_x_vec)
	cross_product(dimension->cam_vector, &v2, dimension->cam_x_vec);
	cross_product(dimension->cam_vector, dimension->cam_x_vec, \
					dimension->cam_y_vec);
}

void	cal_main(t_dimension *dimension)
{
	// double		gx;
	// double		gy;
	// int			i;
	// int			j;
	// t_vector	vec;

	// gx = tan(dimension->cam_fov / 2) * 1;
	// gy = gx * Y_WIN_SIZE / X_WIN_SIZE;
	// i = 0;
	// while (i < X_WIN_SIZE)
	// {
	// 	j = 0;
	// 	while (j < Y_WIN_SIZE)
	// 	{
	// 		vec.x = 2 * gx / (X_WIN_SIZE - 1) * i;
	// 		vec.y = 2 * gy / (Y_WIN_SIZE - 1) * j;
	// 		vec.z = 0;
	// 		shoot_ray(dimension, &vec);
	// 		j++;
	// 	}
	// 	i++;
	// }
	get_cam_vec(dimension);
	vector_print(*dimension->cam_x_vec);
	vector_print(*dimension->cam_y_vec);
	vector_print(*dimension->cam_vector);
}
