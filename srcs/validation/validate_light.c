/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_light.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:15:12 by fsuomins          #+#    #+#             */
/*   Updated: 2023/10/19 20:25:39 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	validate_light(char *line)
{
	char	*str;
	int		count;
	double	value;

	count = 0;
	while ((str = ft_strtok(line, " ")) != NULL)
	{
		if (count == 0 || count == 1 || count == 2)
		{
			value = ft_atoi(str);
			if (value < -180 || value > 180)
				exit_error("Invalid light position.\n");
		}
		else if (count == 3)
		{
			value = atof(str);
			if (value < 0.0 || value > 1.0)
				exit_error("Invalid light intensity.\n");
		}
		else if (count == 4)
		{
			value = ft_atoi(str);
			if (value < 0 || value > 255)
				exit_error("Invalid light color.\n");
		}
		str = NULL;
		count++;
	}
	if (count != 5)
		exit_error("Invalid light definition.\n");
}
