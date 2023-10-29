/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_scene.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 00:02:15 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/10/27 11:17:10 by fsuomins         ###   ########.fr       */
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

static void	validate_line(char *line)
{
	if (line == NULL || *line == '\0' || *line == '\n')
		return ;
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
	free(line);
}
