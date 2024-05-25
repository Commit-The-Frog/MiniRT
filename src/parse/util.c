#include "minirt.h"

void	error_handler(char *msg)
{
	ft_putstr_fd("[ERROR] ", 2);
	ft_putendl_fd(msg, 2);
	exit(1);
}

void	file_controller(t_info *info)
{
	if (info->argc != 2)
		error_handler("argument error");
	info->fd = open(info->argv[1], O_RDONLY);
}

void	free_double_char_list(char **list)
{
	int	i;

	i = 0;
	while (list[i])
		free(list[i++]);
	free(list);
}

int	get_list_len(char **list)
{
	int	i;

	i = 0;
	while (list[i])
		i++;
	return (i);
}

void	print_dim(t_dim *dim)
{
	t_list	*cur;
	t_light	*light;
	t_obj	*obj;

	printf("-------------------------------------\n");
	printf("<AMBIENT LIGHT>\n");
	printf("type : %u\nratio: %lf\n", dim->amb->type, dim->amb->ratio);
	printf("color: [%lf,%lf,%lf]\n", dim->amb->color->r, dim->amb->color->g, dim->amb->color->b);
	printf("-------------------------------------\n");
	printf("<CAMERA>\n");
	printf("cam_coord : [%lf,%lf,%lf]\n", dim->cam_coord->x, dim->cam_coord->y, dim->cam_coord->z);
	printf("cam_dir : [%lf,%lf,%lf]\n", dim->cam_dir->x, dim->cam_dir->y, dim->cam_dir->z);
	printf("fov : %lf\n", dim->fov);
	cur = dim->llist;
	while (cur)
	{
		light = (t_light *)cur->content;
		printf("-------------------------------------\n");
		printf("<LIGHT>\n");
		printf("light_type: %d\n", light->type);
		printf("light_coord : [%lf,%lf,%lf]\n", light->coord->x, light->coord->y, light->coord->z);
		printf("light_ratio: %lf\n", light->ratio);
		printf("light_color: [%lf,%lf,%lf]\n", light->color->r, light->color->g, light->color->b);
		cur = cur->next;
	}
	cur = dim->olist;
	while (cur)
	{
		obj = (t_obj *)cur->content;
		printf("-------------------------------------\n");
		printf("<OBJECT>\n");
		printf("obj_type: %d\n", obj->type);
		printf("obj_coord : [%lf,%lf,%lf]\n", obj->coord->x, obj->coord->y, obj->coord->z);
		if (obj->vec)
			printf("obj_vec : [%lf,%lf,%lf]\n", obj->vec->x, obj->vec->y, obj->vec->z);
		printf("obj_dia: %lf\n", obj->dia);
		printf("obj_height: %lf\n", obj->height);
		printf("obj_color: [%lf,%lf,%lf]\n", obj->color->r, obj->color->g, obj->color->b);
		cur = cur->next;
	}
	printf("-------------------------------------\n");
}
