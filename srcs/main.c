/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:08:29 by fsuomins          #+#    #+#             */
/*   Updated: 2023/11/13 22:04:49 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

/*
 * Validates the arguments passed to the program.
 * @param argc The number of arguments passed to the program.
 * @param argv The arguments passed to the program.
 * @return void
 */
static void	validate_args(int argc, char **argv)
{
	if (argc != 2)
		print_and_exit("Invalid number of arguments.\n", EINVAL);
	if (!check_file_extention(argv[1], ".rt"))
		print_and_exit("Invalid file extention.\n", ENOEXEC);
}
/*
 * Prints the header of the program.
 * @return void
 */
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

uint32_t	rgba_to_int(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	return (((uint32_t)r << 24) | ((uint32_t)g << 16) | ((uint32_t)b << 8) | a);
}

void	render_try(void *param)
{
	(void)param;
	if (mlx_is_key_down(get_data()->mlx.mlx, MLX_KEY_ESCAPE))
		mlx_close_window(get_data()->mlx.mlx);
	for (int i = 0; i < get_data()->mlx.width; i++)
		for (int j = 0; j <  get_data()->mlx.height; j++)
			mlx_put_pixel(get_data()->mlx.image, i, j, rgba_to_int(255, 0, 0, 255));
}

/**/
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
	mlx_image_to_window(get_data()->mlx.mlx, get_data()->mlx.image, 0, 0);
	mlx_loop_hook(get_data()->mlx.mlx, render_try, NULL);
	mlx_loop(get_data()->mlx.mlx);
	clear_objects();
	mlx_terminate(get_data()->mlx.mlx);
	return (0);
}
