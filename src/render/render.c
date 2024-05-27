/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:04:09 by junkim2           #+#    #+#             */
/*   Updated: 2024/05/27 18:37:48 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	init_mlx(t_info *info)
{
	info->mlx = mlx_init();
	if (!info->mlx)
		error_handler("mlx alloction error");
	info->mlx_win = mlx_new_window(info->mlx, WIN_WIDTH, \
									WIN_HEIGHT, "miniRT");
	if (!info->mlx_win)
		error_handler("mlx alloction error");
	info->img.img = mlx_new_image(info->mlx, WIN_WIDTH, WIN_HEIGHT);
	info->img.addr = mlx_get_data_addr(info->img.img, \
	&info->img.bits_per_pixel, &info->img.line_length, &info->img.endian);
}

void	render_mlx(t_info info)
{
	mlx_put_image_to_window(info.mlx, info.mlx_win, info.img.img, 0, 0);
	mlx_hook(info.mlx_win, 2, 0, &key, &info);
	mlx_hook(info.mlx_win, 17, 0, &mlx_exit, &info);
	mlx_loop(info.mlx);
}

unsigned long	rgb_to_hex(t_color color)
{
	unsigned long	hex;
	int				r;
	int				g;
	int				b;

	r = (int)round(color.r);
	g = (int)round(color.g);
	b = (int)round(color.b);
	hex = (r << 16) | (g << 8) | b;
	return (hex);
}
