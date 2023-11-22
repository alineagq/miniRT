/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 15:26:25 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/11/20 19:33:00 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static int	valid_fd(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

static int	validate_line(char *line)
{
	int				i;
	char			*id;
	static t_parse	parse[] = {{"A ", validate_ambient, 0},
	{"C ", validate_camera, 0}, {"L ", validate_light, 0},
	{"sp", validate_sphere,	0}, {"pl", validate_plane, 0},
	{"cy", validate_cylinder, 0}, {NULL, NULL, 0}};

	id = ft_substr(line, 0, 2);
	if (!id)
		return (0);
	i = 0;
	while (parse[i].id && ft_strncmp(id, parse[i].id, 2) != 0)
		i++;
	if (!parse[i].id || parse[i].flag)
	{
		free(id);
		return (0);
	}
	if (i < 3)
		parse[i].flag = 1;
	free(id);
	return (parse[i].validate(++line));
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
		removeDoubleSpacesAndTabs(file_scene.line);
		if (file_scene.line[0] == '\n')
		{
			free(file_scene.line);
			file_scene.line = get_next_line(file_scene.fd);
			continue ;
		}
		if (!validate_line(file_scene.line))
			file_scene.valid = print_line_error(file_scene.line);
		free(file_scene.line);
		file_scene.line = get_next_line(file_scene.fd);
	}
	free(file_scene.line);
	close(file_scene.fd);
	return (file_scene.valid);
}