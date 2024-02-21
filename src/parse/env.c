#include "minirt.h"

void	parse_type_A(t_dimension *dimension, char **list)
{
	t_light	*ambient;

	if (get_list_len(list) != 3)
		error_handler("syntax error : <Ambient light>");
	ambient = (t_light *)ft_calloc(1, sizeof(t_light));
	if (ambient == NULL)
		error_handler("allocation error");
	ambient->type = AMBIENT_LIGHT;
	ambient->coord = NULL;
	ambient->bright_ratio = conv_to_double(list[1]);
	ambient->color = conv_to_color(list[2]);
	dimension->ambient = ambient;
}

void	parse_type_C(t_dimension *dimension, char **list)
{
	if (get_list_len(list) != 4)
		error_handler("syntax error : <Camera>");
	dimension->cam_coord = conv_to_coord(list[1]);
	dimension->cam_vector = conv_to_vector(list[2]);
	dimension->cam_fov = conv_to_double(list[3]);
}

void	parse_type_L(t_dimension *dimension, char **list)
{
	t_light	*light;

	if (get_list_len(list) != 4)
		error_handler("syntax error : <Light>");
	light = (t_light *)ft_calloc(1, sizeof(t_light));
	if (light == NULL)
		error_handler("allocation error");
	light->type = LIGHT;
	light->coord = conv_to_coord(list[1]);
	light->bright_ratio = conv_to_double(list[2]);
	light->color = conv_to_color(list[3]);
	ft_lstadd_back(&(dimension->light_list), ft_lstnew((void *)light));
}
