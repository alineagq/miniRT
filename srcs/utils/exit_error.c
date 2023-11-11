/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:34:42 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/11/10 23:48:52 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	exit_error(char *message, char **split)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(message, 2);
	if (split)
		free_split(split);
	exit(1);
}

void	print_and_exit(char *message, int exit_code)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(message, 2);
	exit(exit_code);
}

int	check_file_extention(const char *str, const char *ext)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
		i++;
	while (ext[j])
		j++;
	if (i < j)
		return (0);
	while (j >= 0)
	{
		if (str[i] != ext[j])
			return (0);
		i--;
		j--;
	}
	return (1);
}