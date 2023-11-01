/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_scene.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 00:02:15 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/10/31 22:02:15 by fsuomins         ###   ########.fr       */
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
	int				i;
	char			*id;
	const t_parse	parse[] = {{"R", NULL}, {"A", validate_ambient}, {"C",
		validate_camera}, {"L", validate_light}, {"sp", validate_sphere}, {"pl",
		validate_plane}, {"cy", validate_cylinder}, {"sq", NULL}, {"tr", NULL},
	{NULL, NULL}};

	id = ft_strtok(line, " ");
	if (!id)
		return (0);
	i = 0;
	while (parse[i].id && !ft_strncmp(id, parse[i].id, 2))
		i++;
	free(id);
	if (parse[i].id)
		return (print_line_error(line));
	return (parse[i].validate(line));
}

int	print_line_error(char *line)
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
	while (file_scene.line && file_scene.valid == 1 && file_scene.line[0] != '\0')
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
