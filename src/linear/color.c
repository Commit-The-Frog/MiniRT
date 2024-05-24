#include "minirt.h"

// add two color c1 + c2 (max:255)
t_color	csum(t_color c1, t_color c2)
{
	if (c1.r + c2.r <= 255)
		c1.r += c2.r;
	else
		c1.r = 255;
	if (c1.g + c2.g <= 255)
		c1.g += c2.g;
	else
		c2.r = 255;
	if (c1.b + c2.b <= 255)
		c1.b += c2.b;
	else
		c1.b = 255;
	return (c1);	
}

// scala multiply of color c1 * sc
t_color	csmul(t_color c1, double sc)
{
	if (c1.r * sc <= 255)
		c1.r *= sc;
	else
		c1.r = 255;
	if (c1.g * sc <= 255)
		c1.g *= sc;
	else
		c1.g = 255;
	if (c1.b * sc <= 255)
		c1.b *= sc;
	else
		c1.b = 255;
	return (c1);
}
