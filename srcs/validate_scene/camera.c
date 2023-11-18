/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 15:35:15 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/11/18 16:08:20 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static int	validate_camera_fov(char *line)
{
	t_camera	cam;
	double		fov;
	double		ratio;
	double		half_view;

	cam = get_data()->camera;
	fov = ft_atoi(line);
	if (fov < 0 || fov > 180 || errno == ERANGE)
		return (0);
	cam.fov = fov / 180 * M_PI;
	half_view = tan(cam.fov / 2);
	ratio = (double)WIDTH / (double) WIDTH / ASPECT_RATIO;
	cam.viewport.width = half_view * ratio;
	cam.viewport.height = half_view;
	if (ratio >= 1)
	{
		cam.viewport.width = half_view;
		cam.viewport.height = half_view / ratio;
	}
	cam.viewport.pixel_size = (cam.viewport.width * 2) / WIDTH;
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
	char **split;

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
	free_split(split);
	return (1);
}
