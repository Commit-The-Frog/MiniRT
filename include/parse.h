#ifndef PARSE_H
# define PARSE_H

#include "minirt.h"

//	parse.c
void		parse(t_info *info, t_dim *dim);
//	util.c
void		error_handler(char *msg);
void		file_controller(t_info *info);
void		free_double_char_list(char **list);
int			get_list_len(char **list);
void		print_dim(t_dim *dim);
//	type.c
void		parse_type_A(t_dim *dim, char **list);
void		parse_type_C(t_dim *s_dim, char **list);
void		parse_type_L(t_dim *dim, char **list);
void		parse_type_obj(t_dim *dim, char **list, t_type type);
//	convert.c
double		conv_to_double(char *str);
t_color		*conv_to_color(char *str);
t_coord		*conv_to_coord(char *str);
t_vec		*conv_to_vector(char *str);

#endif
