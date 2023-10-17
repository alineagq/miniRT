/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_scene.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 00:02:15 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/10/17 10:39:49 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static int	valid_fd(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		printf("Error\n File not found\n");
		exit(0);
	}
	return (fd);
}

static void	validate_line(char *line)
{
	if (line[0] == 'A')
		validate_ambient(line);
	else if (line[0] == 'C')
		validate_camera(line);
	else if (line[0] == 'L')
		validate_light(line);
	else if (strcmp(line, "sp") == 0)
		validate_sphere(line);
	else if (strcmp(line, "pl") == 0)
		validate_plane(line);
	else if (strcmp(line, "cy") == 0)
		validate_cylinder(line);
	else
	{
		free(line);
		exit_error("Invalid scene file.");
	}
}

void	validate_scene(char *file)
{
	int		fd;
	char	*line;

	fd = valid_fd(file);
	line = get_next_line(fd);
	while (line)
	{
		validate_line(line);
		free(line);
		line = get_next_line(fd);
	}
}
