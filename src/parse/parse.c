/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:59:33 by junkim2           #+#    #+#             */
/*   Updated: 2024/05/27 17:59:34 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// exit with free list
void	exit_with_free(char **list, char *msg)
{
	free_double_char_list(list);
	error_handler(msg);
}

void	init_dim(t_dim *dim)
{
	dim->count_a = 0;
	dim->count_l = 0;
	dim->count_c = 0;
	dim->fov = 0;
	dim->llist = NULL;
	dim->olist = NULL;
}

int	parse_line(t_dim *dim, char *line)
{
	char	**list;

	if (line == 0)
		return (1);
	list = ft_split(line, ' ');
	if (list == NULL)
		error_handler("allocation error");
	if (!ft_strncmp(list[0], "A", 1) && ft_strlen(list[0]) == 1)
		parse_type_a(dim, list);
	else if (!ft_strncmp(list[0], "C", 1) && ft_strlen(list[0]) == 1)
		parse_type_c(dim, list);
	else if (!ft_strncmp(list[0], "L", 1) && ft_strlen(list[0]) == 1)
		parse_type_l(dim, list);
	else if (!ft_strncmp(list[0], "sp", 2) && ft_strlen(list[0]) == 2)
		parse_type_obj(dim, list, SP);
	else if (!ft_strncmp(list[0], "pl", 2) && ft_strlen(list[0]) == 2)
		parse_type_obj(dim, list, PL);
	else if (!ft_strncmp(list[0], "cy", 2) && ft_strlen(list[0]) == 2)
		parse_type_obj(dim, list, CY);
	else if (!(!ft_strncmp(list[0], "\n", 1) && ft_strlen(list[0]) == 1) && \
			!(!ft_strncmp(list[0], "#", 1) && ft_strlen(list[0]) == 1))
		exit_with_free(list, "invalid token detected");
	free_double_char_list(list);
	return (0);
}

void	parse(t_info *info, t_dim *dim)
{
	char	*line;

	file_controller(info);
	init_dim(dim);
	line = "";
	while (line)
	{
		line = get_next_line(info->fd);
		parse_line(dim, line);
		free(line);
	}
	if (dim->count_a == 0 || dim->count_c == 0 || dim->count_l == 0)
		error_handler("scene must have at least one A, C, L");
	if (dim->count_a > 1 || dim->count_c > 1)
		error_handler("scene cannot have more than one A, C");
}
