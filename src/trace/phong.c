#include "minirt.h"

// Specular
// (기존 색) * (spec 색) / 255 * (spec ratio)
t_color	specular(t_vec ray, t_hit hit, t_light light)
{
	t_color	res;
	t_color	light_color;
	t_vec	l;
	t_vec	n;
	t_vec	r;
	double	angle;

	// 결과 색 초기화
	init_color(0, 0, 0, &res);
	// 법선벡터 n
	n = hit.vec;
	// 광원과 물체접점을 잇는 난반사 벡터 l 구하기
	l = coord2_to_vec(*light.coord, hit.point);
	// normalize
	norm(&n);
	norm(&l);
	// 정반사 벡터 r 구하기 (r = l + 2 * (-l * n) * n)
	r = vsum(l, vsmul(n, vdot(vsmul(l, -1), n) * 2));
	// 각도에 따른 빛의 양 구하기 : 0~1
	angle = pow(max(vdot(r, vsmul(ray, -1)), 0), 3);
	// 광원의 색비율 구하기
	light_color = csdiv(*light.color, 255);
	// 색상 구하기 : (물체색) * (광원색비율) * (광원밝기) * (각도밝기)
	res = csmul(csmul(cmul(hit.obj_color, light_color), light.ratio), angle);
	return (res);
}

// Diffuse
// (기존 색) * (dif 색) / 255 * (dif ratio)
t_color	diffuse(t_hit hit, t_light light)
{
	t_color	res;
	t_color	light_color;
	t_vec	l;
	t_vec	n;
	double	angle;

	// 결과 색 초기화
	init_color(0, 0, 0, &res);
	// 법선벡터 n
	n = hit.vec;
	// 광원과 물체접점을 잇는 난반사 벡터 l 구하기
	l = coord2_to_vec(hit.point, *light.coord);
	// normalize
	norm(&n);
	norm(&l);
	// n과 l의 내적 구하기 (빛의 각도에 따른 양 계산 : 0~1)
	angle = max(vdot(n, l), 0);
	// 광원의 색비율 구하기
	light_color = csdiv(*light.color, 255);
	// 색상 구하기: (물체색) * (광원색비율) * (광원밝기) * (각도밝기)
	res = csmul(csmul(cmul(hit.obj_color, light_color), light.ratio), angle);
	return (res);
}


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
unsigned long	phong(t_vec ray, t_hit *hit, t_dim *dim)
{
	t_color	res;
	t_list	*llist;
	t_list	*olist;
	int		flag;

	if (!hit->hitted)
		return (0x00);
	llist = dim->llist;
	olist = dim->olist;
	init_color(0, 0, 0, &res);
	// ambient
	res = csum(res, ambient(hit->obj_color, dim->amb));
	// diffuse
	while (llist)
	{
		flag = 0;
		while (olist)
		{
			if (is_hitted(hit->point, *((t_light *)llist->content)->coord, \
				(t_obj *)olist->content, hit->my))
			{
				flag = 1;
				break;
			}
			olist = olist->next;
		}
		if (!flag)
		{
			res = csum(res, diffuse(*hit, *(t_light *)llist->content));
			res = csum(res, specular(ray, *hit, *(t_light *)llist->content));
		}
		llist = llist->next;
	}
	return (rgb_to_hex(res));
}
