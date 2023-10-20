/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_camera.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:13:39 by fsuomins          #+#    #+#             */
/*   Updated: 2023/10/20 11:07:56 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static void	validate_camera_orientation(char *line)
{
	
}

static void	validate_camera_position(char *line)
{
	char	**split;

	split = ft_split(line, ',');
	if (!split[0])
		exit_error("Invalid camera position.\n");
	if (!split[1])
		exit_error("Invalid camera position.\n");
	if (!split[2])
		exit_error("Invalid camera position.\n");
}

void	validate_camera(char *line)
{
	char	**split;

	while (*line == ' ')
		line++;
	split = ft_split(line, ' ');
	if (*line == '\0' || *line == '\n')
		exit_error("Invalid camera.\n");
	validate_camera_position(split[0]);
	validate_camera_orientation(line);
	// validate_viewport(line);
}
