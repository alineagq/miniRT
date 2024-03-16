/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 21:55:17 by aqueiroz          #+#    #+#             */
/*   Updated: 2024/03/15 23:36:14 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static int	validate_ambient_light(char *line)
{
	t_data	*data;
	double	ambient_light;

	data = get_data();
	ambient_light = ft_atof(line);
	if (ambient_light < 0 || ambient_light > 1 || errno == ERANGE)
		return (0);
	data->ambient.ratio = ambient_light;
	return (1);
}

int	validate_ambient(char *line)
{
	char	**split;

	while (*line == ' ')
		line++;
	split = ft_split(line, ' ');
	if (split[0] == NULL || split[1] == NULL || split[2] != NULL)
	{
		free_split(split);
		return (0);
	}
	if (!validate_ambient_light(split[0]) || !validate_color(split[1],
			&get_data()->ambient.color))
	{
		free_split(split);
		return (0);
	}
	free_split(split);
	return (1);
}