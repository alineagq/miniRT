/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_sphere.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:15:52 by fsuomins          #+#    #+#             */
/*   Updated: 2023/11/04 22:10:18 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static int	validate_sphere_position(char *line)
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
	if (!is_numeric_string(split[0]) || split[1] != NULL
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
	add_object(sp, &get_data()->sphere);
	free_split(split);
	return (1);
}
