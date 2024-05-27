#include "minirt.h"

void	check_leak()
{
	system("leaks miniRT");
}

int main(int argc, char *argv[])
{
	t_info	info;
	t_dim	dim;

	atexit(check_leak);
	info.argc = argc;
	info.argv = argv;
	init_mlx(&info);
	parse(&info, &dim);
	cal_main(&dim, &info);
	render_mlx(info);
    return 0;
}
