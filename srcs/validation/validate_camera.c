/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_camera.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:13:39 by fsuomins          #+#    #+#             */
/*   Updated: 2023/11/07 22:03:09 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static int	validate_camera_fov(char *line)
{
	t_data	*data;
	double	fov;

	data = get_data();
	fov = ft_atoi(line);
	if (fov < 0 || fov > 180 || errno == ERANGE)
		return (0);
	data->camera.fov = fov;
	return (1);
}

int	validate_orientation(char *str1, char *str2, char *str3)
{
	if (!str1 || !str2 || !str3)
		return (0);
	if (!ft_is_numeric_string(str1) || !ft_is_numeric_string(str2)
		|| !ft_is_numeric_string(str3))
		return (0);
	if (ft_atof(str1) < -1.0 || ft_atof(str1) > 1.0 || ft_atof(str2) < -1.0
		|| ft_atof(str2) > 1.0 || ft_atof(str3) < -1.0 || ft_atof(str3) > 1.0)
		return (0);
	return (1);
}

static int	validate_camera_orientation(char *line)
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
	data->camera.direction.x = ft_atof(split[0]);
	data->camera.direction.y = ft_atof(split[1]);
	data->camera.direction.z = ft_atof(split[2]);
	free_split(split);
	return (1);
}

static int	validate_camera_position(char *line)
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
	data->camera.origin.x = ft_atof(split[0]);
	data->camera.origin.y = ft_atof(split[1]);
	data->camera.origin.z = ft_atof(split[2]);
	free_split(split);
	return (1);
}

int	validate_camera(char *line)
{
	char	**split;
	t_data	*rt;

	line++;
	while (*line == ' ')
		line++;
	split = ft_split(line, ' ');
	if (!split[0] || !split[1] || !split[2] || split[3] != NULL)
	{
		free_split(split);
		return (0);
	}
	if (!validate_camera_position(split[0])
		|| !validate_camera_orientation(split[1])
		|| !validate_camera_fov(split[2]))
	{
		free_split(split);
		return (0);
	}
	rt = get_data();
	rt->camera.view_range = tan((rt->camera.fov * 0.5) * (M_PI / 180));
	rt->camera.world = camera_show(rt->camera.origin, rt->camera.direction);
	free_split(split);
	return (1);
}
