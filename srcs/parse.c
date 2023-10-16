/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:21:39 by fsuomins          #+#    #+#             */
/*   Updated: 2023/10/16 11:22:20 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_data	*parse_scene(const char *scene_file)
{
	FILE	*file;
	t_data	*data;
	char	line[256];
	char	identifier;

	// Open the scene file
	file = fopen(scene_file, "r");
	if (file == NULL)
	{
		perror("Error opening file");
		return (NULL);
	}
	data = (t_data *)malloc(sizeof(t_data));
	if (data == NULL)
	{
		fclose(file);
		perror("Memory allocation failed");
		return (NULL);
	}
	// Initialize data members to NULL or default values
	data->camera = NULL;
	data->ambient = NULL;
	data->lights = NULL;
	data->objects = NULL;
	// Parse the scene file line by line
	while (fgets(line, sizeof(line), file))
	{
		if (sscanf(line, " %c", &identifier) != 1)
			continue ; // Skip empty lines or lines without an identifier
		switch (identifier)
		{
		case 'A':
			parse_ambient(line, data);
			break ;
		case 'C':
			parse_camera(line, data);
			break ;
		case 'L':
			parse_light(line, data);
			break ;
		case 's':
			parse_sphere(line, data);
			break ;
		case 'p':
			parse_plane(line, data);
			break ;
		case 'c':
			parse_cylinder(line, data);
			break ;
		default:
			break ; // Ignore unknown identifiers
		}
	}
	fclose(file);
	return (data);
}

void	parse_ambient(const char *line, t_data *data)
{
	// Parse ambient lighting information and update data structure
	// Implementation not provided in this example
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