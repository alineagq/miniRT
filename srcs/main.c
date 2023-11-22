/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:08:29 by fsuomins          #+#    #+#             */
/*   Updated: 2023/11/20 19:17:44 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static void	validate_args(int argc, char **argv)
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

int	main(int argc, char **argv)
{
	print_header();
	validate_args(argc, argv);
	init_camera();
	init_objects();
	init_resolution();
	render();
	window_loop();
	clear_objects();
	return (0);
}
