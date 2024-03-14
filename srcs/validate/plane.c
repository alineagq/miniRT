/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 22:08:01 by aqueiroz          #+#    #+#             */
/*   Updated: 2024/03/13 20:10:51 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static int	validate_plane_orientation(char *line)
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
	data->plane.direction.x = ft_atof(split[0]);
	data->plane.direction.y = ft_atof(split[1]);
	data->plane.direction.z = ft_atof(split[2]);
	free_split(split);
	return (1);
}

static int	validate_plane_position(char *line)
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
	data->plane.origin.x = ft_atof(split[0]);
	data->plane.origin.y = ft_atof(split[1]);
	data->plane.origin.z = ft_atof(split[2]);
	free_split(split);
	return (1);
}

static void	set_plane(t_plane *plane)
{
	plane->transform = identity_matrix();
	plane->material = default_material(plane->color);
	plane->transform = transform_cy_pl(plane->direction, plane->origin,
			plane->transform);
	plane->invert = inverse_matrix(plane->transform);
}

int	validate_plane(char *line)
{
	char	**split;

	line++;
	while (*line == ' ')
		line++;
	split = ft_split(line, ' ');
	if (!split[0] || !split[1] || !split[2] || split[3] != NULL)
	{
		free_split(split);
		return (0);
	}
	if (!validate_plane_position(split[0])
		|| !validate_plane_orientation(split[1]) || !validate_color(split[2],
			&get_data()->plane.color))
	{
		free_split(split);
		return (0);
	}
	add_object(PLANE, &get_data()->plane);
	set_plane(&get_data()->plane);
	free_split(split);
	return (1);
}
