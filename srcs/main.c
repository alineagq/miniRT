/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:08:29 by fsuomins          #+#    #+#             */
/*   Updated: 2023/11/03 15:53:16 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static void	validate_args(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 2)
	{
		ft_putstr_fd("Error\n", 1);
		ft_putstr_fd("Usage: ./miniRT <*.rt>\n", 1);
		exit(1);
	}
	while (argv[1][i])
		i++;
	if (argv[1][i - 1] != 't' || argv[1][i - 2] != 'r' || argv[1][i - 3] != '.')
	{
		printf("Error\n");
		printf("File extension must be <*.rt>.\n");
		exit(1);
	}
}

static void	print_header(void)
{
	printf("\n");
	printf(COLOR_PL_1);
	printf("___________________________________________________________\n");
	printf("|                                                         |\n");
	printf("|                                           Created by:   |\n");
	printf("|          _)  _    _)  _ \\ __ __|             fsuomins   |\n");
	printf("|     ` \\   |    \\   |    /    |               aqueiroz   |\n");
	printf("|   _|_|_| _| _| _| _| _|\\_   _|                          |\n");
	printf("|                                                         |\n");
	printf("|_________________________________________________________|\n");
	printf(COLOR_NO);
	printf("\n");
}

int	main(int argc, char **argv)
{
	print_header();
	validate_args(argc, argv);
	if (!validate_scene(argv[1]))
		return (1);
	// parse_scene(argv[1]);
	printf("Data.ambient.ratio: %f\n", get_data()->ambient.ratio);
	printf("Data.ambient.color.r: %d\n", get_data()->ambient.color.r);
	printf("Data.ambient.color.g: %d\n", get_data()->ambient.color.g);
	printf("Data.ambient.color.b: %d\n", get_data()->ambient.color.b);
	printf("Data.camera.fov: %f\n", get_data()->camera.fov);
	printf("Data.camera.origin.x: %f\n", get_data()->camera.origin.x);
	printf("Data.camera.origin.y: %f\n", get_data()->camera.origin.y);
	printf("Data.camera.origin.z: %f\n", get_data()->camera.origin.z);
	printf("Data.camera.direction.x: %f\n", get_data()->camera.direction.x);
	printf("Data.camera.direction.y: %f\n", get_data()->camera.direction.y);
	printf("Data.camera.direction.z: %f\n", get_data()->camera.direction.z);
	printf("Data.light.origin.x: %f\n", get_data()->light.origin.x);
	printf("Data.light.origin.y: %f\n", get_data()->light.origin.y);
	printf("Data.light.origin.z: %f\n", get_data()->light.origin.z);
	printf("Data.light.ratio: %f\n", get_data()->light.ratio);
	printf("Data.light.color.r: %d\n", get_data()->light.color.r);
	printf("Data.light.color.g: %d\n", get_data()->light.color.g);
	printf("Data.light.color.b: %d\n", get_data()->light.color.b);
	return (0);
}
