/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:08:29 by fsuomins          #+#    #+#             */
/*   Updated: 2023/11/15 00:16:03 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static void	validate_args(int argc, char **argv)
{
	if (argc != 2)
		print_and_exit("Invalid number of arguments.\n", EINVAL);
	if (!check_file_extention(argv[1], ".rt"))
		print_and_exit("Invalid file extention.\n", ENOEXEC);
}

int	main(int argc, char **argv)
{
	print_header();
	validate_args(argc, argv);
	init_resolution();
	window_loop();
	return (0);
}
