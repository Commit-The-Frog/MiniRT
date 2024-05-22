/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:02:39 by minjacho          #+#    #+#             */
/*   Updated: 2024/05/22 16:20:58 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// void	shoot_ray(t_dim *dim, t_vec *vec)
// {

// }

void	get_cam_dir(t_dim *dim)
{
	t_vec	v2;

	v2.x = 0;
	v2.y = 0;
	v2.z = 1;
	dim->cam_xv = malloc(sizeof(t_vec));
	if (!dim->cam_xv)
		error_handler("allocation error");
	dim->cam_yv = malloc(sizeof(t_vec));
	if (!dim->cam_yv)
		error_handler("allocation error");
	dim->cam_zv = malloc(sizeof(t_vec));
	if (!dim->cam_zv)
		error_handler("allocation error");
	dim->cam_zv->x = dim->cam_dir->x;
	dim->cam_zv->y = dim->cam_dir->y;
	dim->cam_zv->z = dim->cam_dir->z;
	if (v2.x == dim->cam_dir->x && v2.y == dim->cam_dir->y && \
		v2.z == dim->cam_dir->z)
	{
		dim->cam_xv->x = 1;
		dim->cam_xv->y = 0;
		dim->cam_xv->z = 0;
		dim->cam_yv->x = 0;
		dim->cam_yv->y = 1;
		dim->cam_yv->z = 0;
		return ;
	}
	cross_product(dim->cam_dir, &v2, dim->cam_xv);
	cross_product(dim->cam_dir, dim->cam_xv, \
					dim->cam_yv);
	normalize(dim->cam_xv);
	normalize(dim->cam_yv);
	normalize(dim->cam_zv);
}

void	make_cam_matrix(t_dim *dim, double matrix[][4])
{
	matrix[0][0] = dim->cam_xv->x;
	matrix[0][1] = dim->cam_xv->y;
	matrix[0][2] = dim->cam_xv->z;
	matrix[0][3] = 0;
	matrix[1][0] = dim->cam_yv->x;
	matrix[1][1] = dim->cam_yv->y;
	matrix[1][2] = dim->cam_yv->z;
	matrix[1][3] = 0;
	matrix[2][0] = dim->cam_zv->x;
	matrix[2][1] = dim->cam_zv->y;
	matrix[2][2] = dim->cam_zv->z;
	matrix[2][3] = 0;
	matrix[3][0] = 0;
	matrix[3][1] = 0;
	matrix[3][2] = 0;
	matrix[3][3] = 1;
}

void	make_tran_matrix(t_dim *dim, double matrix[][4])
{
	matrix[0][0] = 1;
	matrix[0][1] = 0;
	matrix[0][2] = 0;
	matrix[0][3] = -dim->cam_coord->x;
	matrix[1][0] = 0;
	matrix[1][1] = 1;
	matrix[1][2] = 0;
	matrix[1][3] = -dim->cam_coord->y;
	matrix[2][0] = 0;
	matrix[2][1] = 0;
	matrix[2][2] = 1;
	matrix[2][3] = -dim->cam_coord->z;
	matrix[3][0] = 0;
	matrix[3][1] = 0;
	matrix[3][2] = 0;
	matrix[3][3] = 1;
}

void	axis_transformer(t_dim *dim)
{
	double	cam_dir[4][4];
	double	tran_vec[4][4];
	double	result[4][4];

	make_cam_matrix(dim, cam_dir);
	make_tran_matrix(dim, tran_vec);
	maxtrix_mul_4_by_4(cam_dir, tran_vec, result);
	// 모든 light list와 obj list에 대해서 값들을 변경해주어야 된다.
}

void	cal_main(t_dim *dim)
{
	double		gx;
	double		gy;
	int			i;
	int			j;
	t_vec	vec;

	get_cam_dir(dim);
	axis_transformer(dim);
	gx = tan(dim->fov / 2) * 1;
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
			// shoot_ray(dim, &vec);
			j++;
		}
		i++;
	}
}
