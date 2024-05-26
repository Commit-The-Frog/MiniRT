#include "minirt.h"

double	conv_to_double(char *str)
{
	int		i;
	int		sign;
	double	result;
	double	div;

	sign = 1;
	result = 0;
	i = 0;
	div = 10.0f;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (str[i] && str[i] != '\n' && (ft_isdigit(str[i]) || str[i] == '.'))
	{
		if (str[i] == '.')
		{
			i++;
			while (str[i] && str[i] != '\n' && ft_isdigit(str[i]))
			{
				result += (double)(str[i] - '0') / div;
				div *= 10;
				i++;
			}
			break;
		}
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	if (str[i] != '\0' && str[i] != '\n')
		error_handler("not a number");
	return (result * sign);
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
