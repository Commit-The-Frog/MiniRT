#include "minirt.h"

t_color	ambient(t_light *amb)
{
	return (csmul(*amb->color, amb->ratio));
}

// trace ray from object to light
unsigned long	phong(t_hit *hit, t_list *llist, t_light *amb)
{
	t_color	color;

	(void)llist;
	color_print(hit->obj_color);
	color = csum(hit->obj_color, ambient(amb));
	if (hit->hitted)
		return (rgb_to_hex(&color));
	else
		return (0x00);
}