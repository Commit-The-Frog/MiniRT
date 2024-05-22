#include "minirt.h"

void	init_obj(t_obj *obj)
{
	obj->coord = NULL;
	obj->vec = NULL;
	obj->dia = 0;
	obj->height = 0;
	obj->color = NULL;
}

void	parse_type_cy(t_dim *dim, char **list)
{
	t_obj	*obj;

	if (get_list_len(list) != 6)
		error_handler("syntax error : <Cylinder>");
	obj = (t_obj *)ft_calloc(1, sizeof(t_obj));
	if (obj == NULL)
		error_handler("allocation error");
	init_obj(obj);
	obj->type = CY;
	obj->coord = conv_to_coord(list[1]);
	obj->vec = conv_to_vec(list[2]);
	obj->dia = conv_to_double(list[3]);
	obj->height = conv_to_double(list[4]);
	obj->color = conv_to_color(list[5]);
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
	init_obj(obj);
	obj->type = PL;
	obj->coord = conv_to_coord(list[1]);
	obj->vec = conv_to_vec(list[2]);
	obj->color = conv_to_color(list[3]);
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
	init_obj(obj);
	obj->type = SP;
	obj->coord = conv_to_coord(list[1]);
	obj->dia = conv_to_double(list[2]);
	obj->color = conv_to_color(list[3]);
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