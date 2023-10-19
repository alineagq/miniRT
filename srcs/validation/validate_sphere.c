/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_sphere.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:15:52 by fsuomins          #+#    #+#             */
/*   Updated: 2023/10/19 12:00:56 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	validate_sphere(char *line)
{
	char	*str;
	int		count;
	int		value;
	int		value;
	int		value;

	count = 0;
	while ((str = strtok(line, " ")) != NULL)
	{
		if (count == 0 || count == 1 || count == 2)
		{
			value = atoi(str);
			if (value < -180 || value > 180)
				exit_error("Invalid sphere position.\n");
		}
		else if (count == 3)
		{
			value = atoi(str);
			if (value < 0)
				exit_error("Invalid sphere radius.\n");
		}
		else if (count == 4)
		{
			value = atoi(str);
			if (value < 0 || value > 255)
				exit_error("Invalid sphere color.\n");
		}
		str = NULL;
		count++;
	}
	if (count != 5)
		exit_error("Invalid sphere definition.\n");
}
