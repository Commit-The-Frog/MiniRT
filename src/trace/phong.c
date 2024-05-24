#include "minirt.h"

// (원래 물체 색) * (amb 색깔) / 255 * (amb ratio)
t_color	ambient(t_color obj_color, t_light *amb)
{
	return (cmul(csmul(csdiv(*amb->color, 255), amb->ratio), obj_color));
}

// trace ray from object to light
// calculate amount of light to ratio(0-1),
// returns color value (unsigned int)
unsigned long	phong(t_hit *hit, t_list *llist, t_light *amb)
{
	(void)llist;
	if (hit->hitted)
		return (rgb_to_hex(ambient(hit->obj_color, amb)));
	else
		return (0x00);
}