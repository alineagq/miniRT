/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_light.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:15:12 by fsuomins          #+#    #+#             */
/*   Updated: 2023/10/31 21:51:31 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static void	validate_light_brightness(char *line)
{
	char	**split;

	split = ft_split(line, ' ');
	if ((ft_atof(split[0]) < 0.0 && ft_atof(split[0]) > 1.0))
		exit_error("Invalid light.\n", split);
	free_split(split);
}

static void	validate_light_position(char *line)
{
	char	**split;

	split = ft_split(line, ',');
	if (!split[0])
		exit_error("Invalid light position.\n", split);
	if (!split[1])
		exit_error("Invalid light position.\n", split);
	if (!split[2])
		exit_error("Invalid light position.\n", split);
	free_split(split);
}

int	validate_light(char *line)
{
	char	**split;

	line++;
	while (*line == ' ')
		line++;
	split = ft_split(line, ' ');
	if (*line == '\0' || *line == '\n')
		exit_error("Invalid light.\n", split);
	validate_light_position(split[0]);
	validate_light_brightness(split[1]);
	validate_color(split[2]);
	free_split(split);
	return (1);
}
