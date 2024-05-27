/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:06:10 by junkim2           #+#    #+#             */
/*   Updated: 2024/05/27 18:06:11 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "minirt.h"

typedef struct s_conv
{
	int		i;
	int		sign;
	double	result;
	double	div;
}	t_conv;

//	parse.c
void		exit_with_free(char **list, char *msg);
void		parse(t_info *info, t_dim *dim);
//	util.c
int			check_extension(char *filename);
void		error_handler(char *msg);
void		file_controller(t_info *info);
void		free_double_char_list(char **list);
int			get_list_len(char **list);
void		print_dim(t_dim *dim);
//	type.c
void		parse_type_a(t_dim *dim, char **list);
void		parse_type_c(t_dim *s_dim, char **list);
void		parse_type_l(t_dim *dim, char **list);
void		parse_type_obj(t_dim *dim, char **list, t_type type);
//	convert.c
double		conv_to_double(char *str);
t_color		conv_to_color(char *str);
t_coord		conv_to_coord(char *str);
t_vec		conv_to_vec(char *str);
//	verify.c
double		verify_ratio(char *str);
t_color		verify_rgb(char *str);
t_vec		verify_vector(char *str);
double		verify_fov(char *str);
double		verify_length(char *str);

#endif
