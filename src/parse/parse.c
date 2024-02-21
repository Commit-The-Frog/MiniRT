#include "minirt.h"

void	init_dimension(t_dimension *dimension)
{
	dimension->cam_coord = NULL;
	dimension->cam_vector = NULL;
	dimension->cam_fov = 0;
	dimension->ambient = NULL;
	dimension->light_list = NULL;
	dimension->obj_list = NULL;
}

int	parse_line(t_dimension *dimension, char *line)
{
	char	**list;

	if (line == 0)
		return (1);
	list = ft_split(line, ' ');
	if (list == NULL)
		error_handler("allocation error");
	if (list[0] && !ft_strncmp(list[0], "A", 1) && ft_strlen(list[0]) == 1)
		parse_type_A(dimension, list);
	else if (list[0] && !ft_strncmp(list[0], "C", 1) && ft_strlen(list[0]) == 1)
		parse_type_C(dimension, list);
	else if (list[0] && !ft_strncmp(list[0], "L", 1) && ft_strlen(list[0]) == 1)
		parse_type_L(dimension, list);
	else if (list[0] && !ft_strncmp(list[0], "sp", 1) && ft_strlen(list[0]) == 2)
		parse_type_obj(dimension, list, SPHERE);
	else if (list[0] && !ft_strncmp(list[0], "pl", 1) && ft_strlen(list[0]) == 2)
		parse_type_obj(dimension, list, PLANE);
	else if (list[0] && !ft_strncmp(list[0], "cy", 1) && ft_strlen(list[0]) == 2)
		parse_type_obj(dimension, list, CYLINDER);
	free_double_char_list(list);
	return (0);
}

void	parse(t_info *info, t_dimension *dimension)
{
	char	*line;

	file_controler(info);
	init_dimension(dimension);
	line = "";
	while (line)
	{
		line = get_next_line(info->fd);
		parse_line(dimension, line);
	}
	print_dimension(dimension);
}