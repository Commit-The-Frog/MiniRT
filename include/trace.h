/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:51:48 by junkim2           #+#    #+#             */
/*   Updated: 2024/05/27 17:52:10 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRACE_H
# define TRACE_H

# include "minirt.h"

typedef struct s_screen
{
	double	gx;
	double	gy;
	t_vec	dx;
	t_vec	dy;
	int		i;
	int		j;
	t_vec	origin;
	t_vec	ray;
}	t_screen;

/* ray.c */
void			cal_main(t_dim *dim, t_info *info);

/* phong.c  */
unsigned long	phong(t_vec ray, t_hit hit, t_dim dim);

#endif