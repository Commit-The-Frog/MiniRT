#ifndef PARSE_H
# define PARSE_H

#include "minirt.h"

//	parse.c
void		parse(t_info *info, t_dimension *dimension);
//	util.c
void		error_handler(char *msg);
void		file_controler(t_info *info);
void		free_double_char_list(char **list);
int			get_list_len(char **list);
void		print_dimension(t_dimension *dimension);
//	type.c
void		parse_type_A(t_dimension *dimension, char **list);
void		parse_type_C(t_dimension *s_dimension, char **list);
void		parse_type_L(t_dimension *dimension, char **list);
void		parse_type_obj(t_dimension *dimension, char **list, t_type type);
//	convert.c
double		conv_to_double(char *str);
t_color		*conv_to_color(char *str);
t_coord		*conv_to_coord(char *str);
t_vector	*conv_to_vector(char *str);

#endif