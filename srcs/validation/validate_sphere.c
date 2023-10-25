/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_sphere.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:15:52 by fsuomins          #+#    #+#             */
/*   Updated: 2023/10/25 15:45:35 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static void	validate_sphere_radius(char *line)
{
	char	**split;

	split = ft_split(line, ' ');
	if ((ft_atof(split[0]) < 0.0))
		exit_error("Invalid sphere radius.\n");
}

static void	validate_sphere_position(char *line)
{
	char	**split;

	split = ft_split(line, ',');
	if (!split[0])
		exit_error("Invalid sphere position.\n");
	if (!split[1])
		exit_error("Invalid sphere position.\n");
	if (!split[2])
		exit_error("Invalid sphere position.\n");
}

void	validate_sphere(char *line)
{
	char	**split;
	while (*line == ' ')
		line++;
	split = ft_split(line, ' ');
	if (*line == '\0' || *line == '\n')
		exit_error("Invalid sphere.\n");
	validate_sphere_position(split[1]);
	validate_sphere_radius(split[2]);
	validate_color(split[3]);
}
