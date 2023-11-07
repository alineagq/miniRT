/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_camera.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:13:39 by fsuomins          #+#    #+#             */
/*   Updated: 2023/11/07 03:23:42 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	is_numeric_string(const char *str)
{
	int	dot_found;

	if (*str == '\0')
		return (0);
	if (*str == '-')
		str++;
	dot_found = 0;
	while (*str)
	{
		if (ft_isdigit(*str))
			str++;
		else if (*str == '.' && !dot_found)
		{
			dot_found = 1;
			str++;
		}
		else if (*str == '\n')
			return (1);
		else
			return (0);
	}
	return (1);
}

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
	if (!is_numeric_string(str1) || !is_numeric_string(str2)
		|| !is_numeric_string(str3))
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
	if (!is_numeric_string(split[0]) || !is_numeric_string(split[1])
		|| !is_numeric_string(split[2]))
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

t_vector	vec_sub(t_vector v1, t_vector v2)
{
	return ((t_vector){v1.x - v2.x, v1.y - v2.y, v1.z - v2.z});
}

t_vector	vec_cross(t_vector v1, t_vector v2)
{
	return ((t_vector){v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z,
		v1.x * v2.y - v1.y * v2.x});
}

t_mat4	mat4_identity(void)
{
	t_mat4	identity;
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
			identity.data[i][j++] = 0;
		i++;
	}
	identity.data[0][0] = 1;
	identity.data[1][1] = 1;
	identity.data[2][2] = 1;
	identity.data[3][3] = 1;
	return (identity);
}

t_vector	vec_normalize(t_vector v)
{
	double	len;

	len = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	return ((t_vector){v.x / len, v.y / len, v.z / len});
}

t_mat4	camera_show(t_vector origem, t_vector focus)
{
	t_vector	up;
	t_vector	right;
	t_vector	forward;
	t_mat4		rotation;

	forward = vec_normalize(vec_sub(focus, origem));
	right = vec_normalize(vec_cross(forward, (t_vector){0, 1, 0}));
	up = vec_normalize(vec_cross(right, forward));
	rotation = mat4_identity();
	rotation.data[0][0] = right.x;
	rotation.data[0][1] = right.y;
	rotation.data[0][2] = right.z;
	rotation.data[1][0] = up.x;
	rotation.data[1][1] = up.y;
	rotation.data[1][2] = up.z;
	rotation.data[2][0] = forward.x;
	rotation.data[2][1] = forward.y;
	rotation.data[2][2] = forward.z;
	return (rotation);
}

t_vector	vec_add(t_vector v1, t_vector v2)
{
	return ((t_vector){v1.x + v2.x, v1.y + v2.y, v1.z + v2.z});
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
