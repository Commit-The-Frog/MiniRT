#include "minirt.h"

// verify RATIO value
// if valid, returns double value
// if invalid, program exit with freeing every data
double	verify_ratio(char *str)
{
	double res;

	res = conv_to_double(str);
	if (res < 0 || 1 < res)
		error_handler("RATIO value must be in range 0 ~ 1");
	return (res);
}

// verify RGB value
// if valid, returns double value
// if invalid, program exit with freeing every data
t_color	verify_rgb(char *str)
{
	t_color	res;

	res = conv_to_color(str);
	if (res.r < 0 || 255 < res.r || res.g < 0 || 255 < res.g || \
		res.b < 0 || 255 < res.b)
		error_handler("RGB color must be in range 0 ~ 255");
	return (res);
}

// verify VECTOR value
// if valid, returns double value
// if invalid, program exit with freeing every data
t_vec	verify_vector(char *str)
{
	t_vec	res;

	res = conv_to_vec(str);
	if (res.x < -1 || 1 < res.x || res.y < -1 || 1 < res.y || \
		res.z < -1 || 1 < res.z)
		error_handler("VECTOR value must be in range -1 ~ 1");
	return (res);
}

// verify FOV value
// if valid, returns double value
// if invalid, program exit with freeing every data
double	verify_fov(char *str)
{
	double	res;

	res = conv_to_double(str);
	if (res < 0 || 180 < res)
		error_handler("FOV value must be in range 0 ~ 180");
	return (res);
}

// verify DIAMETER/HEIGHT value
// if valid, returns double value
// if invalid, program exit with freeing every data
double	verify_length(char *str)
{
	double res;

	res = conv_to_double(str);
	if (res < 0)
		error_handler("DIAMETER/HEIGHT must be bigger than 0");
	return (res);
}