#include "minirt.h"

void	error_handler(char *msg)
{
	ft_putendl_fd(msg, 1);
	exit(1);
}