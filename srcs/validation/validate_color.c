/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:58:49 by fsuomins          #+#    #+#             */
/*   Updated: 2023/11/01 13:19:05 by fsuomins         ###   ########.fr       */
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

int	validate_color(char *line)
{
	char	**split;

	split = ft_split(line, ',');
	if (!split[0] || (ft_atoi(split[0]) < 0 && ft_atoi(split[0]) > 255))
		exit_error("Invalid color.\n", split);
	if (!split[1] || (ft_atoi(split[1]) < 0 && ft_atoi(split[1]) > 255))
		exit_error("Invalid color.\n", split);
	if (!split[2] || (ft_atoi(split[2]) < 0 && ft_atoi(split[2]) > 255))
		exit_error("Invalid color.\n", split);
	free_split(split);
	return (1);
}
