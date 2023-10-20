/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_camera.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:13:39 by fsuomins          #+#    #+#             */
/*   Updated: 2023/10/19 21:50:42 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

double	ft_atof(const char *nptr)
{
	double	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\n'
		|| nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == '\r')
		i++;
	if (nptr[i] == '-')
		sign = -1;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
		result = result * 10 + (nptr[i++] - '0');
	if (nptr[i] == '.')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
		result = result * 10 + (nptr[i++] - '0');
	return (result * sign);
}

static void	validate_viewport(char *line)
{
	char	*str;

	str = ft_strtok(line, " ");
	if (ft_atof(str) > 0)
	{
		str = ft_strtok(NULL, " ");
		if (ft_atof(str) > 0)
		{
			str = ft_strtok(NULL, " ");
			if (str == NULL)
				exit_error("Invalid viewport.\n");
		}
		else
			exit_error("Invalid viewport.\n");
	}
	else
		exit_error("Invalid viewport.\n");
}

static void	validate_camera_orientation(char *line)
{
	char	*str;

	str = ft_strtok(line, ",");
	if (ft_atof(str) >= -1 && ft_atof(str) <= 1)
	{
		str = ft_strtok(NULL, ",");
		if (ft_atof(str) >= -1 && ft_atof(str) <= 1)
		{
			str = ft_strtok(NULL, " ");
			if (ft_atof(str) >= -1 && ft_atof(str) <= 1)
			{
				str = ft_strtok(NULL, " ");
				if (str == NULL)
					exit_error("Invalid camera orientation.\n");
			}
			else
				exit_error("Invalid camera orientation.\n");
		}
		else
			exit_error("Invalid camera orientation.\n");
	}
	else
		exit_error("Invalid camera orientation.\n");
}

static void	validate_camera_position(char *line)
{
	char	*str;
	char	*str2;

	str2 = ft_strdup(line);
	str = ft_strtok(str2, ",");
	if (ft_atof(str))
	{
		line += ft_strlen(str) + 1;
		free(str2);
		str2 = ft_strdup(line);
		str = ft_strtok(NULL, ",");
		if (ft_atof(str))
		{
			str = ft_strtok(NULL, " ");
			if (ft_atof(str))
			{
				str = ft_strtok(NULL, ",");
				if (str == NULL)
					exit_error("Invalid camera position1.\n");
			}
			else
				exit_error("Invalid camera position2.\n");
		}
		else
			exit_error("Invalid camera position3.\n");
	}
	else
		exit_error("Invalid camera position4.\n");
}

void	validate_camera(char *line)
{
	while (*line == ' ')
		line++;
	if (*line == '\0' || *line == '\n')
		exit_error("Invalid camera.\n");
	validate_camera_position(line);
	validate_camera_orientation(line);
	validate_viewport(line);
}