/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:58:49 by fsuomins          #+#    #+#             */
/*   Updated: 2023/11/01 15:48:09 by fsuomins         ###   ########.fr       */
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

int	validate_color(char *line, t_color *color)
{
	char	**split;

	while (*line == ' ')
		line++;
	split = ft_split(line, ',');
	if (!split[0] || (ft_atoi(split[0]) < 0 || ft_atoi(split[0]) > 255))
	{
		free_split(split);
		return (0);
	}
	if (!split[1] || (ft_atoi(split[1]) < 0 || ft_atoi(split[1]) > 255))
	{
		free_split(split);
		return (0);
	}
	if (!split[2] || (ft_atoi(split[2]) < 0 || ft_atoi(split[2]) > 255))
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
