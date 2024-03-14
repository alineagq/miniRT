/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 21:17:28 by aqueiroz          #+#    #+#             */
/*   Updated: 2024/03/13 10:53:51 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void validate_args(int argc, char **argv)
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
