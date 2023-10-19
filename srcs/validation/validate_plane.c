/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_plane.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:39:39 by fsuomins          #+#    #+#             */
/*   Updated: 2023/10/19 12:02:08 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	validate_plane(char *line)
{
	char	*str;
	int		count;
	int		value;
	int		value;
	int		value;

	count = 0;
	while ((str = ft_strtok(line, " ")) != NULL)
	{
		if (count == 0 || count == 1 || count == 2)
		{
			value = ft_atoi(str);
			if (value < -180 || value > 180)
				exit_error("Invalid plane position.\n");
		}
		else if (count == 3)
		{
			value = ft_atoi(str);
			if (value < -180 || value > 180)
				exit_error("Invalid plane orientation.\n");
		}
		else if (count == 4)
		{
			value = ft_atoi(str);
			if (value < 0 || value > 255)
				exit_error("Invalid plane color.\n");
		}
		str = NULL;
		count++;
	}
	if (count != 5)
		exit_error("Invalid plane definition.\n");
}
