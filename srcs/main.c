/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:08:29 by fsuomins          #+#    #+#             */
/*   Updated: 2023/11/07 21:47:20 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"
// #include <memory.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>

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

// int	new_buffer(mlx_image_t *buffer, void *mlx, const int width, const int height)
// {
// 	buffer = mlx_new_image(mlx, width, height);
// 	if (!buffer)
// 		return (0);
// 	return (1);
// }

void	init_resolution(void)
{
	t_data	*data;

	data = get_data();
	data->mlx.width = WIDTH;
	data->mlx.height = HEIGHT;
	data->mlx.mlx = mlx_init(data->mlx.width, data->mlx.height, "miniRT", 0);
	data->ratio = (double)data->mlx.width / (double)data->mlx.height;
// 	if (!new_buffer(data->mlx.image, data->mlx.mlx, data->mlx.width, data->mlx.height))
// 		return ;
}

int	main(int argc, char **argv)
{
	print_header();
	validate_args(argc, argv);
	if (!validate_scene(argv[1]))
	{
		clear_objects();
		return (1);
	}
	init_resolution();
	// mlx_image_to_window(get_data()->mlx.mlx, get_data()->mlx.image, 0, 0);
	mlx_loop(get_data()->mlx.mlx);
	mlx_terminate(get_data()->mlx.mlx);
	clear_objects();
	return (0);
}
