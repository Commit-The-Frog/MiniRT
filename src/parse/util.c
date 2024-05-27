/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:59:43 by junkim2           #+#    #+#             */
/*   Updated: 2024/05/27 18:36:54 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	check_extension(char *filename)
{
	int		i;

	i = 0;
	while (filename[i] && filename[i] != '.')
		i++;
	if (!filename[i] || !filename[i + 1] || !filename[i + 2])
		return (0);
	if (filename[i + 1] == 'r' && filename[i + 2] == 't' && !filename[i + 3])
		return (1);
	return (0);
}

void	error_handler(char *msg)
{
	ft_putstr_fd("ERROR\n", 2);
	ft_putendl_fd(msg, 2);
	exit(1);
}

void	file_controller(t_info *info)
{
	if (info->argc != 2)
		error_handler("argument error");
	if (!check_extension(info->argv[1]))
		error_handler("invaild file extension (*.rt required)");
	info->fd = open(info->argv[1], O_RDONLY);
	if (info->fd < 0)
		error_handler("file not found");
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
