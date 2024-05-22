#include "minirt.h"

int main(int argc, char *argv[])
{
	t_info		info;
	t_dim	dim;

	info.argc = argc;
	info.argv = argv;
	parse(&info, &dim);
	cal_main(&dim);
}
