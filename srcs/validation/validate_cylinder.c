/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_cylinder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:42:10 by fsuomins          #+#    #+#             */
/*   Updated: 2023/11/04 22:32:43 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static int	validate_cylinder_position(char *line)
{
	t_data	*data;
	char	**split;

	data = get_data();
	split = ft_split(line, ',');
	if (!is_numeric_string(split[0]) || !is_numeric_string(split[1])
		|| !is_numeric_string(split[2]))
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
	if (!is_numeric_string(split[0]) || split[1] != NULL
		|| ft_atof(split[0]) < 0)
	{
		free_split(split);
		return (0);
	}
	data->cylinder.diameter = ft_atof(split[0]);
	free_split(split);
	return (1);
}

static int	validate_cylinder_height(char *line)
{
	t_data	*data;
	char	**split;

	data = get_data();
	split = ft_split(line, ' ');
	if (!is_numeric_string(split[0]) || split[1] != NULL
		|| ft_atof(split[0]) < 0)
	{
		free_split(split);
		return (0);
	}
	data->cylinder.height = ft_atof(split[0]);
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
	add_object(cy, &get_data()->cylinder);
	free_split(split);
	return (1);
}
