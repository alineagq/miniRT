/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_plane.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:39:39 by fsuomins          #+#    #+#             */
/*   Updated: 2023/11/03 22:09:07 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

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
	if (!is_numeric_string(split[0]) || !is_numeric_string(split[1])
		|| !is_numeric_string(split[2]))
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

int	validate_plane(char *line)
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
	if (!validate_plane_position(split[0])
		|| !validate_plane_orientation(split[1]) || !validate_color(split[2],
			&get_data()->plane.color))
	{
		free_split(split);
		return (0);
	}
	add_object(pl, &get_data()->plane);
	free_split(split);
	return (1);
}
