#include "minirt.h"

void	parse_type_a(t_dim *dim, char **list)
{
	if (get_list_len(list) != 3)
		error_handler("number of info is invalid : <Amb light>");
	dim->amb.type = AMB;
	dim->amb.ratio = verify_ratio(list[1]);
	dim->amb.color = verify_rgb(list[2]);
	dim->count_a += 1;
}

void	parse_type_c(t_dim *dim, char **list)
{
	if (get_list_len(list) != 4)
		error_handler("number of info is invalid : <Camera>");
	dim->cam_coord = conv_to_coord(list[1]);
	dim->cam_dir = verify_vector(list[2]);
	dim->fov = verify_fov(list[3]);
	dim->count_c += 1;
}

void	parse_type_l(t_dim *dim, char **list)
{
	t_light	*light;

	if (get_list_len(list) != 4)
		error_handler("number of info is invalid : <Light>");
	light = (t_light *)ft_calloc(1, sizeof(t_light));
	if (light == NULL)
		error_handler("allocation error");
	light->type = L;
	light->coord = conv_to_coord(list[1]);
	light->ratio = verify_ratio(list[2]);
	light->color = verify_rgb(list[3]);
	ft_lstadd_back(&(dim->llist), ft_lstnew((void *)light));
	dim->count_l += 1;
}
