/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_scene.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 00:02:15 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/10/31 21:28:59 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static int	valid_fd(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit_error("Invalid scene file.\n", NULL);
	return (fd);
}

static int	validate_line(char *line)
{
	if (line == NULL || *line == '\0' || *line == '\n')
		return (0);
	if (line[0] == 'A')
		validate_ambient(line);
	else if (line[0] == 'C')
		validate_camera(line + 1);
	else if (line[0] == 'L')
		validate_light(line);
	else if (!strncmp(line, "sp", 2))
		validate_sphere(line);
	else if (!strncmp(line, "pl", 2))
		validate_plane(line);
	else if (!strncmp(line, "cy", 2))
		validate_cylinder(line);
	else
	{
		free(line);
		exit_error("Invalid scene file oioi.\n", NULL);
	}
	return (1);
}

static int print_line_error(char *line)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("Invalid line: ", 2);
	ft_putstr_fd(line, 2);
	ft_putstr_fd("\n", 2);
	return (0);
}

int	validate_scene(char *file)
{
	t_file	file_scene;

	file_scene.valid = 1;
	file_scene.fd = valid_fd(file);
	file_scene.line = get_next_line(file_scene.fd);
	while (file_scene.line)
	{
		if (!validate_line(file_scene.line))
			file_scene.valid = print_line_error(file_scene.line);
		free(file_scene.line);
		file_scene.line = get_next_line(file_scene.fd);
	}
	free(file_scene.line);
	close(file_scene.fd);
	return (file_scene.valid);
}
