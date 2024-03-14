/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 22:09:57 by aqueiroz          #+#    #+#             */
/*   Updated: 2024/03/13 20:10:51 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static int	validate_sphere_position(char *line)
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
	data->sphere.origin.x = ft_atof(split[0]);
	data->sphere.origin.y = ft_atof(split[1]);
	data->sphere.origin.z = ft_atof(split[2]);
	free_split(split);
	return (1);
}

static int	validate_sphere_diameter(char *line)
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
	data->sphere.diameter = ft_atof(split[0]);
	free_split(split);
	return (1);
}

int	validate_sphere(char *line)
{
	char		**split;

	line++;
	while (*line == ' ')
		line++;
	split = ft_split(line, ' ');
	if (!split[0] || !split[1] || !split[2] || split[3] != NULL)
	{
		free_split(split);
		return (0);
	}
	if (!validate_sphere_position(split[0])
		|| !validate_sphere_diameter(split[1]) || !validate_color(split[2],
			&get_data()->sphere.color))
	{
		free_split(split);
		return (0);
	}
	get_data()->sphere.radius = ft_atof(split[1]) / 2;
	add_object(SPHERE, &get_data()->sphere);
	free_split(split);
	return (1);
}
