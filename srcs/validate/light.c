/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 22:05:31 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/11/27 10:02:31 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static int	validate_light_brightness(char *line)
{
	t_data	*data;
	char	**split;

	data = get_data();
	split = ft_split(line, ' ');
	if (ft_is_numeric_string(split[0]) == 0)
	{
		free_split(split);
		return (0);
	}
	data->light.ratio = ft_atof(split[0]);
	free_split(split);
	return (1);
}

static int	validate_light_position(char *line)
{
	t_data	*data;
	char	**split;

	data = get_data();
	split = ft_split(line, ',');
	if (ft_is_numeric_string(split[0]) == 0
		|| ft_is_numeric_string(split[1]) == 0
		|| ft_is_numeric_string(split[2]) == 0)
	{
		free_split(split);
		return (0);
	}
	data->light.origin.x = ft_atof(split[0]);
	data->light.origin.y = ft_atof(split[1]);
	data->light.origin.z = ft_atof(split[2]);
	free_split(split);
	return (1);
}

int	validate_light(char *line)
{
	char	**split;

	line++;
	while (*line == ' ')
		line++;
	split = ft_split(line, ' ');
	if (*line == '\0' || *line == '\n')
	{
		free_split(split);
		return (0);
	}
	if (!validate_light_position(split[0])
		|| !validate_light_brightness(split[1]) || !validate_color(split[2],
			&get_data()->light.color))
	{
		free_split(split);
		return (0);
	}
	free_split(split);
	get_data()->light.color = create_vector(1, 1, 1);
	return (1);
}
