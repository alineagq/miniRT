/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_plane.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:39:39 by fsuomins          #+#    #+#             */
/*   Updated: 2023/10/24 20:50:00 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static void	validate_plane_orientation(char *line)
{
	char	**split;

	split = ft_split(line, ',');
	if (!split[0] || (ft_atof(split[0]) < -1.0 && ft_atof(split[0]) > 1.0))
		exit_error("Invalid plane orientation.\n");
	if (!split[1] || (ft_atof(split[1]) < -1.0 && ft_atof(split[1]) > 1.0))
		exit_error("Invalid plane orientation.\n");
	if (!split[2] || (ft_atof(split[2]) < -1.0 && ft_atof(split[2]) > 1.0))
		exit_error("Invalid plane orientation.\n");
}

static void	validate_plane_position(char *line)
{
	char	**split;

	split = ft_split(line, ',');
	if (!split[0])
		exit_error("Invalid plane position.\n");
	if (!split[1])
		exit_error("Invalid plane position.\n");
	if (!split[2])
		exit_error("Invalid plane position.\n");
}

void	validate_plane(char *line)
{
	char	**split;

	line++;
	printf("%s\n", line);
	while (*line == ' ')
		line++;
	split = ft_split(line, ' ');
	if (*line == '\0' || *line == '\n')
		exit_error("Invalid plane.\n");
	if (!split[1])
		exit_error("Invalid plane.\n");
	if (!split[2])
		exit_error("Invalid plane.\n");
	if (!split[3])
		exit_error("Invalid plane.\n");
	validate_plane_position(split[0]);
	validate_plane_orientation(split[1]);
	validate_color(split[2]);
}
