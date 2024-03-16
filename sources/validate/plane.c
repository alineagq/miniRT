/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 22:08:01 by aqueiroz          #+#    #+#             */
/*   Updated: 2024/03/16 15:40:30 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static int	validate_plane_orientation(char *line, t_plane *plane)
{
	char	**split;

	split = ft_split(line, ',');
	if (!validate_orientation(split[0], split[1], split[2]))
	{
		free_split(split);
		return (0);
	}
	plane->normal.x = ft_atof(split[0]);
	plane->normal.y = ft_atof(split[1]);
	plane->normal.z = ft_atof(split[2]);
	free_split(split);
	return (1);
}

static int	validate_plane_position(char *line, t_plane *plane)
{
	char	**split;

	split = ft_split(line, ',');
	if (!ft_is_numeric_string(split[0]) || !ft_is_numeric_string(split[1])
		|| !ft_is_numeric_string(split[2]))
	{
		free_split(split);
		return (0);
	}
	plane->position.x = ft_atof(split[0]);
	plane->position.y = ft_atof(split[1]);
	plane->position.z = ft_atof(split[2]);
	free_split(split);
	return (1);
}

int	validate_plane(char *line)
{
	char	**split;
	t_plane	*plane;

	plane = ft_calloc(1, sizeof(t_plane));
	while (*line++ == ' ')
		;
	split = ft_split(line, ' ');
	if (!split[0] || !split[1] || !split[2] || split[3] != NULL)
		return (free_split(split));
	if (!validate_plane_position(split[0], plane)
		|| !validate_plane_orientation(split[1], plane)
		|| !validate_color(split[2], &plane->material.color))
		return (free_split(split));
	plane->material = default_material(plane->material.color);
	add_object(PLANE, plane);
	free_split(split);
	return (1);
}
