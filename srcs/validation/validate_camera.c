/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_camera.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:13:39 by fsuomins          #+#    #+#             */
/*   Updated: 2023/10/23 23:01:16 by fsuomins         ###   ########.fr       */
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
	while (*str != '\0')
	{
		if (ft_isdigit(*str))
			str++;
		else if (*str == '.' && !dot_found)
		{
			dot_found = 1;
			str++;
		}
		else
			return (0);
	}
	return (1);
}

static void	validate_viewport(char *line)
{
	int	view_port;

	view_port = ft_atoi(line);
	line[ft_strlen(line) - 2] = '\0';
	if (!is_numeric_string(line))
		exit_error("Invalide FOV.\n");
	if (view_port < 0 || view_port > 180)
		exit_error("Invalide FOV.\n");
}

static void	validate_camera_orientation(char *line)
{
	char	**split;

	split = ft_split(line, ',');
	if (!split[0] || (ft_atof(split[0]) < -1.0 && ft_atof(split[0]) > 1.0))
		exit_error("Invalid camera orientation.\n");
	if (!split[1] || (ft_atof(split[1]) < -1.0 && ft_atof(split[1]) > 1.0))
		exit_error("Invalid camera orientation.\n");
	if (!split[2] || (ft_atof(split[2]) < -1.0 && ft_atof(split[2]) > 1.0))
		exit_error("Invalid camera orientation.\n");
}

static void	validate_camera_position(char *line)
{
	char	**split;

	split = ft_split(line, ',');
	if (!split[0])
		exit_error("Invalid camera position.\n");
	if (!split[1])
		exit_error("Invalid camera position.\n");
	if (!split[2])
		exit_error("Invalid camera position.\n");
}

void	validate_camera(char *line)
{
	char	**split;

	while (*line == ' ')
		line++;
	split = ft_split(line, ' ');
	if (*line == '\0' || *line == '\n')
		exit_error("Invalid camera.\n");
	validate_camera_position(split[0]);
	validate_camera_orientation(split[1]);
	validate_viewport(split[2]);
}
