#include "minirt.h"

void	file_controler(t_info *info)
{
	if (info->argc != 2)
		error_handler("[ERROR] argument error");
	info->fd = open(info->argv[1], O_RDONLY);
}