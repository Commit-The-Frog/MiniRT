/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:01:28 by junkim2           #+#    #+#             */
/*   Updated: 2024/05/27 18:01:29 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	mlx_exit(t_info *info)
{
	mlx_destroy_image(info->mlx, info->img.img);
	mlx_destroy_window(info->mlx, info->mlx_win);
	exit(1);
}

int	key(int keycode, t_info *info)
{
	if (keycode == 53)
		mlx_exit(info);
	return (1);
}
