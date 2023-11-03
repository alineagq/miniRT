/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_scene.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 00:02:15 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/11/03 20:40:34 by fsuomins         ###   ########.fr       */
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
	static t_parse	parse[] = {
	{"R ", NULL, 0}, {"A ", validate_ambient, 0},
	{"C ", validate_camera, 0}, {"L ", validate_light, 0},
	{"sp", validate_sphere, 0}, {"pl", validate_plane, 0},
	{"cy", validate_cylinder, 0}, {"sq", NULL, 0}, {"tr", NULL, 0},
	{NULL, NULL, 0}};

	id = ft_substr(line, 0, 2);
	if (!id)
		return (0);
	i = 0;
	while (parse[i].id && ft_strncmp(id, parse[i].id, 2) != 0)
		i++;
	free(id);
	if (!parse[i].id || parse[i].flag)
		return (0);
	parse[i].flag = 1;
	return (parse[i].validate(++line));
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
	while (file_scene.line && file_scene.valid == 1
		&& file_scene.line[0] != '\0')
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
