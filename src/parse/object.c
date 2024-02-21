#include "minirt.h"

void	init_obj(t_obj *obj)
{
	obj->coord = NULL;
	obj->vec = NULL;
	obj->dia = 0;
	obj->height = 0;
	obj->color = NULL;
}

void	parse_type_cy(t_dimension *dimension, char **list)
{
	t_obj	*obj;

	if (get_list_len(list) != 6)
		error_handler("syntax error : <Cylinder>");
	obj = (t_obj *)ft_calloc(1, sizeof(t_obj));
	if (obj == NULL)
		error_handler("allocation error");
	init_obj(obj);
	obj->type = CYLINDER;
	obj->coord = conv_to_coord(list[1]);
	obj->vec = conv_to_vector(list[2]);
	obj->dia = conv_to_double(list[3]);
	obj->height = conv_to_double(list[4]);
	obj->color = conv_to_color(list[5]);
	ft_lstadd_back(&(dimension->obj_list), ft_lstnew((void *)obj));
}

void	parse_type_pl(t_dimension *dimension, char **list)
{
	t_obj	*obj;

	if (get_list_len(list) != 4)
		error_handler("syntax error : <Plane>");
	obj = (t_obj *)ft_calloc(1, sizeof(t_obj));
	if (obj == NULL)
		error_handler("allocation error");
	init_obj(obj);
	obj->type = PLANE;
	obj->coord = conv_to_coord(list[1]);
	obj->vec = conv_to_vector(list[2]);
	obj->color = conv_to_color(list[3]);
	ft_lstadd_back(&(dimension->obj_list), ft_lstnew((void *)obj));
}

void	parse_type_sp(t_dimension *dimension, char **list)
{
	t_obj	*obj;

	if (get_list_len(list) != 4)
		error_handler("syntax error : <Sphere>");
	obj = (t_obj *)ft_calloc(1, sizeof(t_obj));
	if (obj == NULL)
		error_handler("allocation error");
	init_obj(obj);
	obj->type = SPHERE;
	obj->coord = conv_to_coord(list[1]);
	obj->dia = conv_to_double(list[2]);
	obj->color = conv_to_color(list[3]);
	ft_lstadd_back(&(dimension->obj_list), ft_lstnew((void *)obj));
}

void	parse_type_obj(t_dimension *dimension, char **list, t_type type)
{
	if (type == SPHERE)
		parse_type_sp(dimension, list);
	else if (type == PLANE)
		parse_type_pl(dimension, list);
	else if (type == CYLINDER)
		parse_type_cy(dimension, list);
}