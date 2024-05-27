#include "minirt.h"

void	free_all(t_info info, t_dim dim)
{
	ft_lstclear(&dim.llist, free);
	ft_lstclear(&dim.olist, free);
	free(info.mlx);
	free(info.mlx_win);
}

void	check_leak(void)
{
	system("leaks miniRT");
}

int	main(int argc, char *argv[])
{
	t_info	info;
	t_dim	dim;

	// atexit(check_leak);
	info.argc = argc;
	info.argv = argv;
	// init_mlx(&info);
	parse(&info, &dim);
	// cal_main(&dim, &info);
	// render_mlx(info);
	// free_all(info, dim);
	return (0);
}
