/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_light.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:15:12 by fsuomins          #+#    #+#             */
/*   Updated: 2023/10/23 22:51:26 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static void	validate__(char *line)
{
	char	**split;

	split = ft_split(line, ',');
	if (!split[0] || (ft_atof(split[0]) < 0.0 && ft_atof(split[0]) > 1.0))
		exit_error("Invalid light.\n");
	if (!split[1] || (ft_atof(split[1]) < 0.0 && ft_atof(split[1]) > 1.0))
		exit_error("Invalid light.\n");
	if (!split[2] || (ft_atof(split[2]) < 0.0 && ft_atof(split[2]) > 1.0))
		exit_error("Invalid light.\n");
}

void	validate_light(char *line)
{
	char	**split;

	while (*line == ' ')
		line++;
	split = ft_split(line, ' ');
	if (*line == '\0' || *line == '\n')
		exit_error("Invalid light1.\n");
	if (!split[0] || !split[1] || !split[2] || !split[3])
		exit_error("Invalid light2.\n");
	if (!is_numeric_string(split[1]))
		exit_error("Invalid light3.\n");
	if (!is_numeric_string(split[2]))
		exit_error("Invalid light4.\n");
	if (!is_numeric_string(split[3]))
		exit_error("Invalid light5.\n");
	validate__(split[1]);
	validate__(split[2]);
	validate__(split[3]);
}
