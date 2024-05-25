#include "minirt.h"

void	init_dim(t_dim *dim)
{
	dim->cam_coord = NULL;
	dim->cam_dir = NULL;
	dim->fov = 0;
	dim->amb = NULL;
	dim->llist = NULL;
	dim->olist = NULL;
}

int	parse_line(t_dim *dim, char *line)
{
	char	**list;

	if (line == 0)
		return (1);
	list = ft_split(line, ' ');
	if (list == NULL)
		error_handler("allocation error");
	if (list[0] && !ft_strncmp(list[0], "A", 1) && ft_strlen(list[0]) == 1)
		parse_type_A(dim, list);
	else if (list[0] && !ft_strncmp(list[0], "C", 1) && ft_strlen(list[0]) == 1)
		parse_type_C(dim, list);
	else if (list[0] && !ft_strncmp(list[0], "L", 1) && ft_strlen(list[0]) == 1)
		parse_type_L(dim, list);
	else if (list[0] && !ft_strncmp(list[0], "sp", 2) && ft_strlen(list[0]) == 2)
		parse_type_obj(dim, list, SP);
	else if (list[0] && !ft_strncmp(list[0], "pl", 2) && ft_strlen(list[0]) == 2)
		parse_type_obj(dim, list, PL);
	else if (list[0] && !ft_strncmp(list[0], "cy", 2) && ft_strlen(list[0]) == 2)
		parse_type_obj(dim, list, CY);
	free_double_char_list(list);
	return (0);
}

void	parse(t_info *info, t_dim *dim)
{
	char	*line;

	file_controller(info);
	init_dim(dim);
	line = "";
	while (line)
	{
		line = get_next_line(info->fd);
		parse_line(dim, line);
	}
	// print_dim(dim);
}