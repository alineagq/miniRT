/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:08:29 by fsuomins          #+#    #+#             */
/*   Updated: 2023/10/22 20:51:12 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static void	validate_args(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 2)
	{
		printf("Usage: %s <scene.rt>\n", argv[0]);
		exit(0);
	}
	while (argv[1][i])
		i++;
	if (argv[1][i - 1] != 't' || argv[1][i - 2] != 'r' || argv[1][i - 3] != '.')
		exit_error("Invalid scene file\n");
}

static void	check_validate(int argc, char **argv)
{
	validate_args(argc, argv);
	validate_scene(argv[1]);
}

void	print_header(void)
{
	printf("\n");
	printf("\033[1;35m");
	printf("************************************\n");
	printf("*                                  *\n");
	printf("*          Welcome to miniRT       *\n");
	printf("*                                  *\n");
	printf("************************************\n");
	printf("\033[0m");
	printf("\n");
}

int	main(int argc, char **argv)
{
	print_header();
	check_validate(argc, argv);
	// parse_scene(argv[1]);
	return (0);
}
