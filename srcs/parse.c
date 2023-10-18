/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:21:39 by fsuomins          #+#    #+#             */
/*   Updated: 2023/10/18 10:15:12 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	*parse_scene(const char *scene_file)
{
	t_data	*data;
	char	*line;
	int		fd;

	data = malloc(sizeof(t_data));
	if (!data)
		exit_error("Malloc error");
	fd = open(scene_file, O_RDONLY);
	if (fd == -1)
		exit_error("File not found");\z
	line = get_next_line(fd);
	while (line)
	{
		if (line[0] == 'A')
			parse_ambient(line, data);
		else if (line[0] == 'C')
			parse_camera(line, data);
		else if (line[0] == 'L')
			parse_light(line, data);
		else if (strcmp(line, "sp") == 0)
			parse_sphere(line, data);
		else if (strcmp(line, "pl") == 0)
			parse_plane(line, data);
		else if (strcmp(line, "cy") == 0)
			parse_cylinder(line, data);
		else
			exit_error("Invalid scene file.");
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (data);

}

void	parse_ambient(const char *line, t_data *data)
{

}

void	parse_camera(const char *line, t_data *data)
{
	// Parse camera information and update data structure
	// Implementation not provided in this example
}

void	parse_light(const char *line, t_data *data)
{
	// Parse light information and update data structure
	// Implementation not provided in this example
}

void	parse_sphere(const char *line, t_data *data)
{
	// Parse sphere information and update data structure
	// Implementation not provided in this example
}

void	parse_plane(const char *line, t_data *data)
{
	// Parse plane information and update data structure
	// Implementation not provided in this example
}

void	parse_cylinder(const char *line, t_data *data)
{
	// Parse cylinder information and update data structure
	// Implementation not provided in this example
}

void	render_scene(t_data *data)
{
	// Implement ray tracing logic to render the scene
	// This involves casting rays, calculating intersections, and shading
	// Update the MiniLibX window accordingly
}

void	free_data(t_data *data)
{
	// Implement logic to free allocated memory for t_data structure
}