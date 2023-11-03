/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_light.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:15:12 by fsuomins          #+#    #+#             */
/*   Updated: 2023/11/02 20:26:14 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

// static void	validate_light_brightness(char *line)
// {
// 	char	**split;

// 	split = ft_split(line, ' ');
// 	if ((ft_atof(split[0]) < 0.0 && ft_atof(split[0]) > 1.0))
// 		exit_error("Invalid light.\n", split);
// 	free_split(split);
// }

static int	validate_light_position(char *line)
{
	t_data	*data;
	char	**split;

	data = get_data();
	split = ft_split(line, ',');
	if (is_numeric_string(split[0]) == 0 || is_numeric_string(split[1]) == 0
		|| is_numeric_string(split[2]) == 0)
	{
		free_split(split);
		return (0);
	}
	data->light.origin.x = is_numeric_string(split[0]);
	data->light.origin.y = is_numeric_string(split[1]);
	data->light.origin.z = is_numeric_string(split[2]);
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
	if (validate_light_position(split[0]) == 0)
	{
		free_split(split);
		return (0);
	}
	if (is_numeric_string(split[1]) == 0)
	{
		free_split(split);
		return (0);
	}
	if (validate_color(split[2], &get_data()->light.color) == 0)
	{
		free_split(split);
		return (0);
	}
	free_split(split);
	return (1);
}
