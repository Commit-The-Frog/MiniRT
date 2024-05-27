/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:59:19 by junkim2           #+#    #+#             */
/*   Updated: 2024/05/27 17:59:20 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_type_cy(t_dim *dim, char **list)
{
	t_obj	*obj;

	if (get_list_len(list) != 6)
		error_handler("syntax error : <Cylinder>");
	obj = (t_obj *)ft_calloc(1, sizeof(t_obj));
	if (obj == NULL)
		error_handler("allocation error");
	obj->type = CY;
	obj->coord = conv_to_coord(list[1]);
	obj->vec = verify_vector(list[2]);
	obj->dia = verify_length(list[3]);
	obj->height = verify_length(list[4]);
	obj->color = verify_rgb(list[5]);
	ft_lstadd_back(&(dim->olist), ft_lstnew((void *)obj));
}

void	parse_type_pl(t_dim *dim, char **list)
{
	t_obj	*obj;

	if (get_list_len(list) != 4)
		error_handler("syntax error : <Plane>");
	obj = (t_obj *)ft_calloc(1, sizeof(t_obj));
	if (obj == NULL)
		error_handler("allocation error");
	obj->type = PL;
	obj->coord = conv_to_coord(list[1]);
	obj->vec = verify_vector(list[2]);
	obj->color = verify_rgb(list[3]);
	ft_lstadd_back(&(dim->olist), ft_lstnew((void *)obj));
}

void	parse_type_sp(t_dim *dim, char **list)
{
	t_obj	*obj;

	if (get_list_len(list) != 4)
		error_handler("syntax error : <Sphere>");
	obj = (t_obj *)ft_calloc(1, sizeof(t_obj));
	if (obj == NULL)
		error_handler("allocation error");
	obj->type = SP;
	obj->coord = conv_to_coord(list[1]);
	obj->dia = verify_length(list[2]);
	obj->color = verify_rgb(list[3]);
	ft_lstadd_back(&(dim->olist), ft_lstnew((void *)obj));
}

void	parse_type_obj(t_dim *dim, char **list, t_type type)
{
	if (type == SP)
		parse_type_sp(dim, list);
	else if (type == PL)
		parse_type_pl(dim, list);
	else if (type == CY)
		parse_type_cy(dim, list);
}
