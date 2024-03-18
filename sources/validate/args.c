/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 21:17:28 by aqueiroz          #+#    #+#             */
/*   Updated: 2024/03/16 15:03:02 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static void	print_and_exit(char *message, int error_code)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd(message, STDERR_FILENO);
	exit(error_code);
}

static int	check_file_extention(const char *str, const char *ext)
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

void	validate_args(int argc, char **argv)
{
	if (argc != 2)
		print_and_exit("Invalid number of arguments.\n", EINVAL);
	if (!check_file_extention(argv[1], ".rt") || ft_strlen(argv[1]) < 4)
		print_and_exit("Invalid file extention.\n", ENOEXEC);
	if (!validate_scene(argv[1]))
	{
		clear_objects();
		print_and_exit("Invalid scene file.\n", EINVAL);
	}
}
