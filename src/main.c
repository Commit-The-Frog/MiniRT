#include "minirt.h"

int main(int argc, char *argv[])
{
	t_info	info;

	info.argc = argc;
	info.argv = argv;
	parse(&info);
}