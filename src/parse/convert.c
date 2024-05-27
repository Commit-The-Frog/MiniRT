/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:59:12 by junkim2           #+#    #+#             */
/*   Updated: 2024/05/27 17:59:12 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	init_conv(t_conv *conv, char *str)
{
	conv->result = 0;
	conv->i = 0;
	conv->sign = 1;
	conv->div = 10.0f;
	if (str[conv->i] == '-')
	{
		conv->sign *= -1;
		conv->i++;
	}
}

double	conv_to_double(char *str)
{
	t_conv	c;

	init_conv(&c, str);
	while (str[c.i] && str[c.i] != '\n' && \
		(ft_isdigit(str[c.i]) || str[c.i] == '.'))
	{
		if (str[c.i] == '.')
		{
			c.i++;
			while (str[c.i] && str[c.i] != '\n' && ft_isdigit(str[c.i]))
			{
				c.result += (double)(str[c.i] - '0') / c.div;
				c.div *= 10;
				c.i++;
			}
			break ;
		}
		c.result *= 10;
		c.result += str[c.i] - '0';
		c.i++;
	}
	if (str[c.i] != '\0' && str[c.i] != '\n')
		error_handler("not a number");
	return (c.result * c.sign);
}

t_color	conv_to_color(char *str)
{
	char	**list;
	t_color	color;

	list = ft_split(str, ',');
	color.r = conv_to_double(list[0]);
	color.g = conv_to_double(list[1]);
	color.b = conv_to_double(list[2]);
	free_double_char_list(list);
	return (color);
}

t_coord	conv_to_coord(char *str)
{
	t_coord	coord;
	char	**list;

	list = ft_split(str, ',');
	coord.x = conv_to_double(list[0]);
	coord.y = conv_to_double(list[1]);
	coord.z = conv_to_double(list[2]);
	free_double_char_list(list);
	return (coord);
}

t_vec	conv_to_vec(char *str)
{
	t_vec	vec;
	char	**list;

	list = ft_split(str, ',');
	vec.x = conv_to_double(list[0]);
	vec.y = conv_to_double(list[1]);
	vec.z = conv_to_double(list[2]);
	free_double_char_list(list);
	return (vec);
}
