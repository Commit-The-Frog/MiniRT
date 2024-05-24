/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjacho <minjacho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:02:39 by minjacho          #+#    #+#             */
/*   Updated: 2024/05/24 16:15:58 by minjacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	shoot_ray(t_dim *dim, t_info *info)
{
	double	gx;
	double	gy;
	t_vec	dx;
	t_vec	dy;
	int		i;
	int 	j;
	t_vec	origin;
	t_vec	ray;
	unsigned long	color;

	gx = tan(dim->fov / 2);
	gy = gx * WIN_HEIGHT / WIN_WIDTH;
	copy_vec(&origin, vsub(vsub(*dim->cam_zv, vsmul(*dim->cam_xv, gx)), vsmul(*dim->cam_yv, gy)));
	copy_vec(&dx, vsmul(*dim->cam_xv, 2 * gx / (WIN_WIDTH - 1)));
	copy_vec(&dy, vsmul(*dim->cam_yv, 2 * gy / (WIN_HEIGHT - 1)));
	i = 0;
	while (i < WIN_HEIGHT)
	{
		j = 0;
		while (j < WIN_WIDTH)
		{
			// make ray (d = origin + j * dx + i * dy)
			copy_vec(&ray, vsum(vsum(origin, vsmul(dx, j)), vsmul(dy, i)));
			norm(&ray);
			// vector_print(ray);
			color = raytrace(&ray, dim);
			my_mlx_pixel_put(&info->img, j, i, color);
			j++;
		}
		i++;
	}
}

// 카메라의 축(vx, vy, vz) 계산
void	get_cam_dir(t_dim *dim)
{
	t_vec	wz;

	init_vec(0, 0, 1, &wz);
	dim->cam_xv = malloc(sizeof(t_vec));
	if (!dim->cam_xv)
		error_handler("allocation error");
	dim->cam_yv = malloc(sizeof(t_vec));
	if (!dim->cam_yv)
		error_handler("allocation error");
	dim->cam_zv = malloc(sizeof(t_vec));
	if (!dim->cam_zv)
		error_handler("allocation error");
	copy_vec(dim->cam_zv, *dim->cam_dir);
	if (comp_vec(wz, *(dim->cam_dir)))
	{
		init_vec(1, 0, 0, dim->cam_xv);
		init_vec(0, 1, 0, dim->cam_yv);
		return ;
	}
	norm(dim->cam_zv);
	*dim->cam_xv = vcross(*dim->cam_zv, wz);
	*dim->cam_yv = vcross(*dim->cam_zv, *dim->cam_xv);
	norm(dim->cam_yv);
	norm(dim->cam_xv);
}

void	cal_main(t_dim *dim, t_info *info)
{
	get_cam_dir(dim);
	shoot_ray(dim, info);
}
