/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:58:49 by fsuomins          #+#    #+#             */
/*   Updated: 2023/10/25 15:59:24 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	validate_color(char *line)
{
	char	**split;

	split = ft_split(line, ',');
	if (!split[0] || (ft_atoi(split[0]) < 0 && ft_atoi(split[0]) > 255))
		exit_error("Invalid color.\n");
	if (!split[1] || (ft_atoi(split[1]) < 0 && ft_atoi(split[1]) > 255))
		exit_error("Invalid color.\n");
	if (!split[2] || (ft_atoi(split[2]) < 0 && ft_atoi(split[2]) > 255))
		exit_error("Invalid color.\n");
}