#include "minirt.h"

void	parse(t_info *info, t_dimension *dimension)
{
	(void)dimension;

	file_controler(info);
	printf("%s", get_next_line(info->fd));
}