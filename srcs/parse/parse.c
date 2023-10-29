/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:21:39 by fsuomins          #+#    #+#             */
/*   Updated: 2023/10/29 15:47:23 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"
#include "../includes/structs.h"

void	*parse_scene(const char *scene_file)
{
	t_data	*data;
	char	*line;
	int		fd;

	data = malloc(sizeof(t_data));
	if (!data)
		exit_error("Malloc error", NULL);
	fd = open(scene_file, O_RDONLY);
	if (fd == -1)
		exit_error("File not found", NULL);
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
			exit_error("Invalid scene file.", &line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (data);
}
void	render_scene(t_data *data)
{
	(void)data;
	return ;
}

void	free_data(t_data *data)
{
	(void)data;
	return ;
}