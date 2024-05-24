#include "minirt.h"

// initialize color to r, g, b
void	init_color(int r, int g, int b, t_color *color)
{
	color->r = r;
	color->g = g;
	color->b = b;
}

// add two color c1 + c2 (max:255)
t_color	csum(t_color c1, t_color c2)
{
	c1.r = min(c1.r + c2.r, 255);
	c1.g = min(c1.g + c2.g, 255);
	c1.b = min(c1.b + c2.b, 255);
	return (c1);	
}

// multiply two color c1 * c2
t_color	cmul(t_color c1, t_color c2)
{
	c1.r *= c2.r;
	c1.g *= c2.g;
	c1.b *= c2.b;
	return (c1);
}

// scala multiply of color c1 * sc
t_color	csmul(t_color c1, double sc)
{
	c1.r = min(c1.r * sc, 255);
	c1.g = min(c1.g * sc, 255);
	c1.b = min(c1.b * sc, 255);
	return (c1);
}

// scala divide of color c1 / sc
t_color	csdiv(t_color c1, double sc)
{
	c1.r /= sc;
	c1.g /= sc;
	c1.b /= sc;
	return (c1);
}
