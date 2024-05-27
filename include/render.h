/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:08:08 by junkim2           #+#    #+#             */
/*   Updated: 2024/05/27 18:08:08 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "minirt.h"

/* hook */
int				mlx_exit(t_info *info);
int				key(int keycode, t_info *info);

/* render.c */
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			init_mlx(t_info *info);
void			render_mlx(t_info info);
unsigned long	rgb_to_hex(t_color color);

#endif
