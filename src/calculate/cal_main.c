/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjacho <minjacho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:02:39 by minjacho          #+#    #+#             */
/*   Updated: 2024/02/22 22:04:39 by minjacho         ###   ########.fr       */
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
	dimension->cam_x_vec = malloc(sizeof(t_vector));
	if (!dimension->cam_x_vec)
		error_handler("allocation error");
	dimension->cam_y_vec = malloc(sizeof(t_vector));
	if (!dimension->cam_y_vec)
		error_handler("allocation error");
	dimension->cam_z_vec = malloc(sizeof(t_vector));
	if (!dimension->cam_z_vec)
		error_handler("allocation error");
	dimension->cam_z_vec->x = dimension->cam_vector->x;
	dimension->cam_z_vec->y = dimension->cam_vector->y;
	dimension->cam_z_vec->z = dimension->cam_vector->z;
	if (v2.x == dimension->cam_vector->x && v2.y == dimension->cam_vector->y && \
		v2.z == dimension->cam_vector->z)
	{
		dimension->cam_x_vec->x = 1;
		dimension->cam_x_vec->y = 0;
		dimension->cam_x_vec->z = 0;
		dimension->cam_y_vec->x = 0;
		dimension->cam_y_vec->y = 1;
		dimension->cam_y_vec->z = 0;
		return ;
	}
	cross_product(dimension->cam_vector, &v2, dimension->cam_x_vec);
	cross_product(dimension->cam_vector, dimension->cam_x_vec, \
					dimension->cam_y_vec);
	normalize(dimension->cam_x_vec);
	normalize(dimension->cam_y_vec);
	normalize(dimension->cam_z_vec);
}

void	make_cam_matrix(t_dimension *dimension, double matrix[][4])
{
	matrix[0][0] = dimension->cam_x_vec->x;
	matrix[0][1] = dimension->cam_x_vec->y;
	matrix[0][2] = dimension->cam_x_vec->z;
	matrix[0][3] = 0;
	matrix[1][0] = dimension->cam_y_vec->x;
	matrix[1][1] = dimension->cam_y_vec->y;
	matrix[1][2] = dimension->cam_y_vec->z;
	matrix[1][3] = 0;
	matrix[2][0] = dimension->cam_z_vec->x;
	matrix[2][1] = dimension->cam_z_vec->y;
	matrix[2][2] = dimension->cam_z_vec->z;
	matrix[2][3] = 0;
	matrix[3][0] = 0;
	matrix[3][1] = 0;
	matrix[3][2] = 0;
	matrix[3][3] = 1;
}

void	make_tran_matrix(t_dimension *dimension, double matrix[][4])
{
	matrix[0][0] = 1;
	matrix[0][1] = 0;
	matrix[0][2] = 0;
	matrix[0][3] = -dimension->cam_coord->x;
	matrix[1][0] = 0;
	matrix[1][1] = 1;
	matrix[1][2] = 0;
	matrix[1][3] = -dimension->cam_coord->y;
	matrix[2][0] = 0;
	matrix[2][1] = 0;
	matrix[2][2] = 1;
	matrix[2][3] = -dimension->cam_coord->z;
	matrix[3][0] = 0;
	matrix[3][1] = 0;
	matrix[3][2] = 0;
	matrix[3][3] = 1;
}

void	axis_transformer(t_dimension *dimension)
{
	double	cam_vec[4][4];
	double	tran_vec[4][4];
	double	result[4][4];

	make_cam_matrix(dimension, cam_vec);
	make_tran_matrix(dimension, tran_vec);
	maxtrix_mul_4_by_4(cam_vec, tran_vec, result);
	// 모든 light list와 obj list에 대해서 값들을 변경해주어야 된다.
}

void	cal_main(t_dimension *dimension)
{
	double		gx;
	double		gy;
	int			i;
	int			j;
	t_vector	vec;

	get_cam_vec(dimension);
	axis_transformer(dimension);
	gx = tan(dimension->cam_fov / 2) * 1;
	gy = gx * Y_WIN_SIZE / X_WIN_SIZE;
	i = 0;
	while (i < X_WIN_SIZE)
	{
		j = 0;
		while (j < Y_WIN_SIZE)
		{
			vec.x = 2 * gx / (X_WIN_SIZE - 1) * i;
			vec.y = 2 * gy / (Y_WIN_SIZE - 1) * j;
			vec.z = 0;
			// shoot_ray(dimension, &vec);
			j++;
		}
		i++;
	}
}
