/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_camera.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:13:39 by fsuomins          #+#    #+#             */
/*   Updated: 2023/10/19 12:06:22 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	validate_camera(char *line)
{
	char	*str;
	int		count;
	int		value;
	double	value;
	int		value;

	count = 0;
	while ((str = ft_strtok(line, " ")) != NULL)
	{
		if (count == 0 || count == 1 || count == 2)
		{
			value = ft_atoi(str);
			if (value < -180 || value > 180)
				exit_error("Invalid camera angle.\n");
		}
		else if (count == 3)
		{
			value = atof(str);
			if (value < 0.0 || value > 1.0)
				exit_error("Invalid camera color intensity.\n");
		}
		else if (count == 4)
		{
			value = ft_atoi(str);
			if (value < 0 || value > 255)
				exit_error("Invalid camera color.\n");
		}
		str = NULL;
		count++;
	}
	if (count != 5)
		exit_error("Invalid camera definition.\n");
}