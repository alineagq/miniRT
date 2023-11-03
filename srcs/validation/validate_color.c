/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:58:49 by fsuomins          #+#    #+#             */
/*   Updated: 2023/11/03 14:34:19 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

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
	return (is_numeric_string(str) && ft_atoi(str) >= 0 && ft_atoi(str) <= 255);
}

int	validate_color(char *line, t_color *color)
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
	color->r = ft_atoi(split[0]);
	color->g = ft_atoi(split[1]);
	color->b = ft_atoi(split[2]);
	free_split(split);
	return (1);
}
