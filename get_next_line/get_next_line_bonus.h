/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 23:35:56 by macbookpro        #+#    #+#             */
/*   Updated: 2024/02/21 17:04:16 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# ifndef FD_LIMIT
#  define FD_LIMIT 100000
# endif

# include <stdlib.h>
# include <unistd.h>

# define _ERROR	0

typedef struct s_list
{
	char	*buff;
	int		total_size;
	int		current_size;
	int		flag;
}	t_list;

char	*get_next_line(int fd);
char	*alloc_double(t_list *lst);
int		gnl_strlen(char *str);
void	*gnl_calloc(int count, int size);
char	*gnl_strchr(char *str, char c);
char	*gnl_strdup(char *s1);
char	*err_handler(t_list *lst);

#endif