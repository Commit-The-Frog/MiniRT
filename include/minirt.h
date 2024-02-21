#ifndef MINIRT_H
# define MINIRT_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "rt_type.h"
# include "parse.h"

typedef struct s_info
{
	int			argc;
	char		**argv;
}	t_info;

#endif