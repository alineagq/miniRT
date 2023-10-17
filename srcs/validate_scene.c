/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_scene.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 00:02:15 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/10/17 00:08:21 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	validate_scene(char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		printf("Error\n File not found\n");
		exit(0);
	}

	line = get_next_line(fd);
	while (line)
	{
		if (line[0] == 'R')
			validate_resolution(line);
		else if (line[0] == 'A')
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
			printf("Error\n Invalid identifier\n");
			free(line);
			exit(0);
		}
		free(line);
		line = get_next_line(fd);
	}
}
