#include "minirt.h"

int main(int argc, char *argv[])
{
	t_info		info;
	t_dimension	dimension;

	info.argc = argc;
	info.argv = argv;
	parse(&info, &dimension);
}