/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 22:09:57 by aqueiroz          #+#    #+#             */
/*   Updated: 2024/03/16 15:49:41 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "../includes/validate.h"

static int	validate_sphere_position(char *line, t_sphere *sphere)
{
	char	**split;

	split = ft_split(line, ',');
	if (!ft_is_numeric_string(split[0]) || !ft_is_numeric_string(split[1])
		|| !ft_is_numeric_string(split[2]))
	{
		free_split(split);
		return (0);
	}
	sphere->center.x = ft_atof(split[0]);
	sphere->center.y = ft_atof(split[1]);
	sphere->center.z = ft_atof(split[2]);
	free_split(split);
	return (1);
}

static int	validate_sphere_diameter(char *line, t_sphere *sphere)
{
	char	**split;

	split = ft_split(line, ' ');
	if (!ft_is_numeric_string(split[0]) || split[1] != NULL
		|| ft_atof(split[0]) < 0)
	{
		free_split(split);
		return (0);
	}
	sphere->radius = ft_atof(split[0]) / 2;
	free_split(split);
	return (1);
}

int	validate_sphere(char *line)
{
	char		**split;
	t_sphere	*sphere;

	sphere = ft_calloc(1, sizeof(t_sphere));
	while (*line++ == ' ')
		;
	split = ft_split(line, ' ');
	if (!split[0] || !split[1] || !split[2] || split[3] != NULL)
		return (free_split(split));
	if (!validate_sphere_position(split[0], sphere)
		|| !validate_sphere_diameter(split[1], sphere)
		|| !validate_color(split[2], &sphere->material.color))
		return (free_split(split));
	sphere->material = default_material(sphere->material.color);
	add_object(SPHERE, sphere);
	free_split(split);
	return (1);
}
