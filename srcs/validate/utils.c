/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 15:36:58 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/11/27 10:07:33 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	validate_orientation(char *str1, char *str2, char *str3)
{
	if (!str1 || !str2 || !str3)
		return (0);
	if (!ft_is_numeric_string(str1) || !ft_is_numeric_string(str2)
		|| !ft_is_numeric_string(str3))
		return (0);
	if (ft_atof(str1) < -1.0 || ft_atof(str1) > 1.0 || ft_atof(str2) < -1.0
		|| ft_atof(str2) > 1.0 || ft_atof(str3) < -1.0 || ft_atof(str3) > 1.0)
		return (0);
	return (1);
}

t_vector	color_multiply(t_vector color, double ratio)
{
	t_vector	new_color;

	new_color.x = color.x * ratio;
	new_color.y = color.y * ratio;
	new_color.z = color.z * ratio;
	return (new_color);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

int	is_valid_color(char *str)
{
	if (!str)
		return (0);
	return (ft_is_numeric_string(str) && ft_atoi(str) >= 0
		&& ft_atoi(str) <= 255);
}

int	validate_color(char *line, t_vector *color)
{
	char	**split;

	while (*line == ' ')
		line++;
	split = ft_split(line, ',');
	if (!is_valid_color(split[0]) || !is_valid_color(split[1])
		|| !is_valid_color(split[2]) || split[3])
	{
		free_split(split);
		return (0);
	}
	color->x = ft_atof(split[0]) / 255;
	color->y = ft_atof(split[1]) / 255;
	color->z = ft_atof(split[2]) / 255;
	free_split(split);
	return (1);
}

t_material	default_material(t_vector color)
{
	t_material	m;

	m.ambient = get_data()->ambient.ratio;
	m.diffuse = 0.9;
	m.specular = 0;
	m.shininess = 200;
	m.color = create_vector(color.x, color.y, color.z);
	return (m);
}
