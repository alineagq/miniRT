/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_ambient.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:14:05 by fsuomins          #+#    #+#             */
/*   Updated: 2023/10/25 15:40:15 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	validate_color(char *line)
{
	char	*str;

	str = ft_strtok(line, ",");
	if (ft_atoi(str) >= 0 && ft_atoi(str) <= 255)
	{
		str = ft_strtok(NULL, ",");
		if (ft_atoi(str) >= 0 && ft_atoi(str) <= 255)
		{
			str = ft_strtok(NULL, ",");
			if (ft_atoi(str) >= 0 && ft_atoi(str) <= 255)
			{
				str = ft_strtok(NULL, ",");
				if (str == NULL)
					return ;
			}
			else
				exit_error("Invalid color.\n");
		}
		else
			exit_error("Invalid color.\n");
	}
	else
		exit_error("Invalid color.\n");
}

void	validate_ambient_light(char *line)
{
	int	i;

	i = 1;
	while (line[i] == ' ')
		i++;
	if (line[i] == '0' && line[i + 1] == '.')
	{
		i += 2;
		while (line[i] >= '0' && line[i] <= '9')
			i++;
		if (line[i] == ' ' || line[i] == '\0')
			return ;
	}
	exit_error("Invalid ambient light.\n");
}

void	validate_ambient(char *line)
{
	int	i;

	i = 1;
	while (line[i] == ' ')
		i++;
	if ((line[i] == '0' || line[i] == 1) && line[i + 1] == '.')
	{
		i += 2;
		while (line[i] >= '0' && line[i] <= '9')
			i++;
		if (line[i] == ' ' || line[i] == '\0')
			validate_color(line + i);
		else
			exit_error("Invalid ambient.\n");
	}
	else
		exit_error("Invalid ambient.\n");
}
