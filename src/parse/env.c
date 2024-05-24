#include "minirt.h"

void	parse_type_A(t_dim *dim, char **list)
{
	t_light	*amb;

	if (get_list_len(list) != 3)
		error_handler("syntax error : <Amb light>");
	amb = (t_light *)ft_calloc(1, sizeof(t_light));
	if (amb == NULL)
		error_handler("allocation error");
	amb->type = AMB;
	amb->coord = NULL;
	amb->ratio = conv_to_double(list[1]);
	amb->color = conv_to_color(list[2]);
	dim->amb = amb;
}

void	parse_type_C(t_dim *dim, char **list)
{
	if (get_list_len(list) != 4)
		error_handler("syntax error : <Camera>");
	dim->cam_coord = conv_to_coord(list[1]);
	dim->cam_dir = conv_to_vec(list[2]);
	dim->fov = conv_to_double(list[3]);
}

void	parse_type_L(t_dim *dim, char **list)
{
	t_light	*light;

	if (get_list_len(list) != 4)
		error_handler("syntax error : <Light>");
	light = (t_light *)ft_calloc(1, sizeof(t_light));
	if (light == NULL)
		error_handler("allocation error");
	light->type = L;
	light->coord = conv_to_coord(list[1]);
	light->ratio = conv_to_double(list[2]);
	light->color = conv_to_color(list[3]);
	ft_lstadd_back(&(dim->llist), ft_lstnew((void *)light));
}
