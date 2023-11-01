/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_cylinder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:42:10 by fsuomins          #+#    #+#             */
/*   Updated: 2023/11/01 16:55:29 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static int	validate_cylinder_orientation(char *line)
{
	char	**split;

	split = ft_split(line, ',');
	if (!split[0] || (ft_atof(split[0]) < -1.0 && ft_atof(split[0]) > 1.0))
	{
		free_split(split);
		return (0);
	}
	if (!split[1] || (ft_atof(split[1]) < -1.0 && ft_atof(split[1]) > 1.0))
	{
		free_split(split);
		return (0);
	}
	if (!split[2] || (ft_atof(split[2]) < -1.0 && ft_atof(split[2]) > 1.0))
	{
		free_split(split);
		return (0);	
	}
	free_split(split);
	return (1);
}

static int	validate_cylinder_radius(char *line)
{
	char	**split;

	split = ft_split(line, ' ');
	if ((ft_atof(split[0]) < 0.0))
	{
		free_split(split);
		return (0);
	}
	free_split(split);
	return (1);
}

static int	validate_cylinder_position(char *line)
{
	char	**split;

	split = ft_split(line, ',');
	if (!split[0])
	{
		free_split(split);
		return (0);
	}
	if (!split[1])
	{
		free_split(split);
		return (0);
	}
	if (!split[2])
	{
		free_split(split);
		return (0);
	}
	free_split(split);
	return (1);
}

static int	validate_cylinder_height(char *line)
{
	char	**split;

	split = ft_split(line, ' ');
	if ((ft_atof(split[0]) < 0.0))
	{
		free_split(split);
		return (0);
	}
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
	if (*line == '\0' || *line == '\n')
	{
		free_split(split);
		return (0);
	}
	validate_cylinder_position(split[1]);
	validate_cylinder_orientation(split[2]);
	validate_cylinder_radius(split[3]);
	validate_cylinder_height(split[4]);
	if (validate_color(split[5], &get_data()->cylinder.color) == 0)
	{
		free_split(split);
		return (0);
	}
	free_split(split);
	return (1);
}

