#include "minirt.h"

void	error_handler(char *msg)
{
	ft_putstr_fd("[ERROR] ", 2);
	ft_putendl_fd(msg, 2);
	exit(1);
}

void	file_controler(t_info *info)
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

void	print_dimension(t_dimension *dimension)
{
	t_list	*cur;
	t_light	*light;
	t_obj	*obj;

	printf("-------------------------------------\n");
	printf("<AMBIENT LIGHT>\n");
	printf("type : %u\nbright_ratio: %lf\n", dimension->ambient->type, dimension->ambient->bright_ratio);
	printf("color: [%d,%d,%d]\n", dimension->ambient->color->r, dimension->ambient->color->g, dimension->ambient->color->b);
	printf("-------------------------------------\n");
	printf("<CAMERA>\n");
	printf("cam_coord : [%lf,%lf,%lf]\n", dimension->cam_coord->x, dimension->cam_coord->y, dimension->cam_coord->z);
	printf("cam_vector : [%lf,%lf,%lf]\n", dimension->cam_vector->x, dimension->cam_vector->y, dimension->cam_vector->z);
	printf("cam_fov : %lf\n", dimension->cam_fov);
	cur = dimension->light_list;
	while (cur)
	{
		light = (t_light *)cur->content;
		printf("-------------------------------------\n");
		printf("<LIGHT>\n");
		printf("light_type: %d\n", light->type);
		printf("light_coord : [%lf,%lf,%lf]\n", light->coord->x, light->coord->y, light->coord->z);
		printf("light_bright_ratio: %lf\n", light->bright_ratio);
		printf("light_color: [%d,%d,%d]\n", light->color->r, light->color->g, light->color->b);
		cur = cur->next;
	}
	cur = dimension->obj_list;
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
		printf("obj_color: [%d,%d,%d]\n", obj->color->r, obj->color->g, obj->color->b);
		cur = cur->next;
	}
	printf("-------------------------------------\n");
}
