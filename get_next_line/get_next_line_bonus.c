/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 23:35:04 by macbookpro        #+#    #+#             */
/*   Updated: 2024/02/21 17:04:15 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*err_handler(t_list *lst)
{
	free(lst->buff);
	lst->buff = NULL;
	lst->current_size = 0;
	lst->total_size = 0;
	lst->flag = 0;
	return (NULL);
}

void	ft_memmove(t_list *lst, int idx)
{
	int	i;

	i = 0;
	while (lst->buff[idx] != 0)
	{
		lst->buff[i] = lst->buff[idx];
		i++;
		idx++;
	}
	lst->current_size = i;
	while (lst->buff[i] != 0)
		lst->buff[i++] = 0;
}

char	*get_left(t_list *lst)
{
	char	*result;
	char	*pos;
	int		len;
	int		i;

	pos = gnl_strchr(lst->buff, '\n');
	if (lst->flag == 1 && pos == NULL)
	{
		result = gnl_strdup(lst->buff);
		if (result == NULL)
			return (err_handler(lst));
		return (result);
	}
	len = pos - lst->buff + 2;
	result = (char *)gnl_calloc(len, sizeof(char));
	if (result == NULL)
		return (err_handler(lst));
	i = 0;
	while (i < len - 1)
	{
		result[i] = lst->buff[i];
		i++;
	}
	ft_memmove(lst, i);
	return (result);
}

char	*read_line(int fd, t_list *lst)
{
	int		read_size;
	char	*tmp;

	if (lst->flag == 0 && lst->total_size - lst->current_size < BUFFER_SIZE)
	{
		tmp = alloc_double(lst);
		if (tmp == NULL)
			return (err_handler(lst));
		lst->buff = tmp;
	}
	read_size = 0;
	while (lst->total_size - lst->current_size >= BUFFER_SIZE && \
gnl_strchr(lst->buff, '\n') == NULL && lst->flag == 0)
	{
		read_size = read(fd, &(lst->buff[lst->current_size]), BUFFER_SIZE);
		if (read_size < 0)
			return (err_handler(lst));
		lst->current_size += read_size;
		if (read_size == 0)
			lst->flag = 1;
	}
	if (lst->flag == 0 && gnl_strchr(lst->buff, '\n') == NULL)
		return (read_line(fd, lst));
	return (lst->buff);
}

char	*get_next_line(int fd)
{
	static t_list	arr[FD_LIMIT];
	char			*result;
	char			*err_flag;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	err_flag = read_line(fd, &arr[fd]);
	if (err_flag == NULL)
		return (NULL);
	if (arr[fd].flag == 1 && arr[fd].buff[0] == 0)
		return (err_handler(&arr[fd]));
	result = get_left(&arr[fd]);
	if (result == _ERROR)
		return (NULL);
	if (arr[fd].flag == 1)
		err_handler(&arr[fd]);
	return (result);
}
