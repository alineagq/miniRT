/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_ambient.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:14:05 by fsuomins          #+#    #+#             */
/*   Updated: 2023/10/30 22:49:35 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	validate_ambient_light(char **split)
{
	t_data	*data;
	double	ambient_light;

	data = get_data();
	ambient_light = ft_atof(split[0]);
	if (ambient_light < 0 || ambient_light > 1)
		exit_error("Invalid ambient light.\n", split);
	data->ambient.ratio = ambient_light;
	printf("Ambient light: %f\n", data->ambient.ratio);
}

void	validate_ambient(char *line)
{
	char	**split;

	while (*line == ' ')
		line++;
	split = ft_split(line, ' ');
	if (split[0] == NULL || split[1] == NULL)
		exit_error("Invalid ambient light.\n", split);
	if (split[2] != NULL)
		exit_error("Invalid ambient light.\n", split);
	validate_ambient_light(split);
	validate_color(split, "Invalid ambient light.\n");
}
