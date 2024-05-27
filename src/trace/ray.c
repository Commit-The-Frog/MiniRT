/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjacho <minjacho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:02:39 by minjacho          #+#    #+#             */
/*   Updated: 2024/05/27 16:02:51 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	init_screen(t_dim dim, t_screen *screen)
{
	screen->gx = tan(M_PI / 180 * dim.fov / 2);
	screen->gy = screen->gx * WIN_HEIGHT / WIN_WIDTH;
	copy_vec(&screen->origin, vsub(vsub(dim.cam_zv, \
			vsmul(dim.cam_xv, screen->gx)), vsmul(dim.cam_yv, screen->gy)));
	copy_vec(&screen->dx, vsmul(dim.cam_xv, 2 * screen->gx / (WIN_WIDTH - 1)));
	copy_vec(&screen->dy, vsmul(dim.cam_yv, 2 * screen->gy / (WIN_HEIGHT - 1)));
}

void	shoot_ray(t_dim dim, t_info *info)
{
	t_screen	s;

	init_screen(dim, &s);
	s.i = 0;
	while (s.i < WIN_HEIGHT)
	{
		s.j = 0;
		while (s.j < WIN_WIDTH)
		{
			copy_vec(&s.ray, vsum(vsum(s.origin, vsmul(s.dx, s.j)), \
					vsmul(s.dy, s.i)));
			norm(&s.ray);
			my_mlx_pixel_put(&info->img, s.j, s.i, raytrace(s.ray, dim));
			s.j++;
		}
		s.i++;
	}
}

// 카메라의 축(vx, vy, vz) 계산
void	get_cam_dir(t_dim *dim)
{
	t_vec	wy;
	t_vec	neg_wy;

	init_vec(0, 1, 0, &wy);
	init_vec(0, -1, 0, &neg_wy);
	copy_vec(&dim->cam_zv, dim->cam_dir);
	if (comp_vec(wy, dim->cam_dir) || comp_vec(neg_wy, dim->cam_dir))
	{
		init_vec(1, 0, 0, &dim->cam_xv);
		init_vec(0, 0, 1, &dim->cam_yv);
		return ;
	}
	norm(&dim->cam_zv);
	dim->cam_xv = vcross(dim->cam_zv, wy);
	norm(&dim->cam_xv);
	dim->cam_yv = vcross(dim->cam_zv, dim->cam_xv);
	norm(&dim->cam_yv);
}

void	cal_main(t_dim *dim, t_info *info)
{
	get_cam_dir(dim);
	shoot_ray(*dim, info);
}
