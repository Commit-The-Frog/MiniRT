/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:08:22 by junkim2           #+#    #+#             */
/*   Updated: 2024/05/27 18:08:28 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	free_all(t_info info, t_dim dim)
{
	ft_lstclear(&dim.llist, free);
	ft_lstclear(&dim.olist, free);
	free(info.mlx);
	free(info.mlx_win);
}

int	main(int argc, char *argv[])
{
	t_info	info;
	t_dim	dim;

	info.argc = argc;
	info.argv = argv;
	init_mlx(&info);
	parse(&info, &dim);
	cal_main(&dim, &info);
	render_mlx(info);
	free_all(info, dim);
	return (0);
}
