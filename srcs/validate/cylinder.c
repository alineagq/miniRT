/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 22:02:42 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/11/27 10:10:39 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static int	validate_cylinder_position(char *line)
{
	t_data	*data;
	char	**split;

	data = get_data();
	split = ft_split(line, ',');
	if (!ft_is_numeric_string(split[0]) || !ft_is_numeric_string(split[1])
		|| !ft_is_numeric_string(split[2]))
	{
		free_split(split);
		return (0);
	}
	data->cylinder.origin.x = ft_atof(split[0]);
	data->cylinder.origin.y = ft_atof(split[1]);
	data->cylinder.origin.z = ft_atof(split[2]);
	free_split(split);
	return (1);
}

static int	validate_cylinder_diameter(char *line)
{
	t_data	*data;
	char	**split;

	data = get_data();
	split = ft_split(line, ' ');
	if (!ft_is_numeric_string(split[0]) || split[1] != NULL
		|| ft_atof(split[0]) < 0)
	{
		free_split(split);
		return (0);
	}
	data->cylinder.diameter = ft_atof(split[0]);
	data->cylinder.radius = data->cylinder.diameter / 2;
	free_split(split);
	return (1);
}

static int	validate_cylinder_height(char *line)
{
	t_data	*data;
	char	**split;

	data = get_data();
	split = ft_split(line, ' ');
	if (!ft_is_numeric_string(split[0]) || split[1] != NULL
		|| ft_atof(split[0]) < 0)
	{
		free_split(split);
		return (0);
	}
	data->cylinder.height = ft_atof(split[0]);
	data->cylinder.min = -(data->cylinder.height / 2);
	data->cylinder.max = data->cylinder.height / 2;
	data->cylinder.transform = identity_matrix();
	data->cylinder.material = default_material(data->cylinder.color);
	free_split(split);
	return (1);
}

static int	validate_cylinder_orientation(char *line)
{
	t_data	*data;
	char	**split;

	data = get_data();
	split = ft_split(line, ',');
	if (!validate_orientation(split[0], split[1], split[2]))
	{
		free_split(split);
		return (0);
	}
	data->cylinder.direction.x = ft_atof(split[0]);
	data->cylinder.direction.y = ft_atof(split[1]);
	data->cylinder.direction.z = ft_atof(split[2]);
	free_split(split);
	return (1);
}

int	validate_cylinder(char *line)
{
	char	**split;

	line++;
	while (*line == ' ')
		line++;
	split = ft_split(line, ' ');
	if (!split[0] || !split[1] || !split[2] || !split[3] || !split[4]
		|| split[5] != NULL)
	{
		free_split(split);
		return (0);
	}
	if (!validate_cylinder_position(split[0])
		|| !validate_cylinder_orientation(split[1])
		|| !validate_cylinder_diameter(split[2])
		|| !validate_cylinder_height(split[3]) || !validate_color(split[4],
			&get_data()->cylinder.color))
	{
		free_split(split);
		return (0);
	}
	get_data()->cylinder.height = fabs(get_data()->cylinder.height);
	add_object(CYLINDER, &get_data()->cylinder);
	free_split(split);
	return (1);
}
