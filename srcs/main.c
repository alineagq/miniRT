/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:08:29 by fsuomins          #+#    #+#             */
/*   Updated: 2023/11/18 15:21:56 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static void	validate_args(int argc, char **argv)
{
	if (argc != 2)
		print_and_exit("Invalid number of arguments.\n", EINVAL);
	if (!check_file_extention(argv[1], ".rt"))
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
	init_resolution();
	window_loop();
	return (0);
}
