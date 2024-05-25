#include "minirt.h"

// Diffuse
// (기존 색) * (dif 색) / 255 * (dif ratio)
 

// Ambient
// (기존 색) * (amb 색) / 255 * (amb ratio)
t_color	ambient(t_color obj_color, t_light *amb)
{
	t_color	res;

	init_color(0, 0, 0, &res);
	if (!amb)
		return (res);
	res = csum(res, cmul(csmul(csdiv(*amb->color, 255), amb->ratio), obj_color));
	return (res);
}

// trace ray from object to light
// calculate amount of light to ratio(0-1),
// returns color value (unsigned int)
unsigned long	phong(t_hit *hit, t_list *llist, t_light *amb)
{
	t_color	res;

	(void)llist;
	init_color(0, 0, 0, &res);
	res = csum(res, ambient(hit->obj_color, amb));	// add ambient
	if (hit->hitted)
		return (rgb_to_hex(res));
	else
		return (0x00);
}