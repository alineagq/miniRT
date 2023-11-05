/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:08:29 by fsuomins          #+#    #+#             */
/*   Updated: 2023/11/04 22:31:00 by aqueiroz         ###   ########.fr       */
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
	int			i;
	t_object	*tmp;

	print_header();
	validate_args(argc, argv);
	if (!validate_scene(argv[1]))
	{
		clear_objects();
		return (1);
	}
	// parse_scene(argv[1]);
	// Dont need free
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
	// Need free
	printf("Data.plane.origin.x: %f\n", get_data()->plane.origin.x);
	printf("Data.plane.origin.y: %f\n", get_data()->plane.origin.y);
	printf("Data.plane.origin.z: %f\n", get_data()->plane.origin.z);
	printf("Data.plane.direction.x: %f\n", get_data()->plane.direction.x);
	printf("Data.plane.direction.y: %f\n", get_data()->plane.direction.y);
	printf("Data.plane.direction.z: %f\n", get_data()->plane.direction.z);
	printf("Data.plane.color.r: %d\n", get_data()->plane.color.r);
	printf("Data.plane.color.g: %d\n", get_data()->plane.color.g);
	printf("Data.plane.color.b: %d\n", get_data()->plane.color.b);
	i = 0;
	tmp = get_data()->objects;
	while (tmp)
	{
		if (tmp->id == pl)
		{
			printf("Data.objects[%d].plane.origin.x: %f\n", i, ((t_plane *)tmp->object)->origin.x);
			printf("Data.objects[%d].plane.origin.y: %f\n", i, ((t_plane *)tmp->object)->origin.y);
			printf("Data.objects[%d].plane.origin.z: %f\n", i, ((t_plane *)tmp->object)->origin.z);
			printf("Data.objects[%d].plane.direction.x: %f\n", i, ((t_plane *)tmp->object)->direction.x);
			printf("Data.objects[%d].plane.direction.y: %f\n", i, ((t_plane *)tmp->object)->direction.y);
			printf("Data.objects[%d].plane.direction.z: %f\n", i, ((t_plane *)tmp->object)->direction.z);
			printf("Data.objects[%d].plane.color.r: %d\n", i, ((t_plane *)tmp->object)->color.r);
			printf("Data.objects[%d].plane.color.g: %d\n", i, ((t_plane *)tmp->object)->color.g);
			printf("Data.objects[%d].plane.color.b: %d\n", i, ((t_plane *)tmp->object)->color.b);
		}
		if (tmp->id == sp)
		{
			printf("Data.objects[%d].sphere.origin.x: %f\n", i, ((t_sphere *)tmp->object)->origin.x);
			printf("Data.objects[%d].sphere.origin.y: %f\n", i, ((t_sphere *)tmp->object)->origin.y);
			printf("Data.objects[%d].sphere.origin.z: %f\n", i, ((t_sphere *)tmp->object)->origin.z);
			printf("Data.objects[%d].sphere.diameter: %f\n", i, ((t_sphere *)tmp->object)->diameter);
			printf("Data.objects[%d].sphere.color.r: %d\n", i, ((t_sphere *)tmp->object)->color.r);
			printf("Data.objects[%d].sphere.color.g: %d\n", i, ((t_sphere *)tmp->object)->color.g);
			printf("Data.objects[%d].sphere.color.b: %d\n", i, ((t_sphere *)tmp->object)->color.b);
		}
		if (tmp->id == cy)
		{
			printf("Data.objects[%d].cylinder.origin.x: %f\n", i, ((t_cylinder *)tmp->object)->origin.x);
			printf("Data.objects[%d].cylinder.origin.y: %f\n", i, ((t_cylinder *)tmp->object)->origin.y);
			printf("Data.objects[%d].cylinder.origin.z: %f\n", i, ((t_cylinder *)tmp->object)->origin.z);
			printf("Data.objects[%d].cylinder.direction.x: %f\n", i, ((t_cylinder *)tmp->object)->direction.x);
			printf("Data.objects[%d].cylinder.direction.y: %f\n", i, ((t_cylinder *)tmp->object)->direction.y);
			printf("Data.objects[%d].cylinder.direction.z: %f\n", i, ((t_cylinder *)tmp->object)->direction.z);
			printf("Data.objects[%d].cylinder.diameter: %f\n", i, ((t_cylinder *)tmp->object)->diameter);
			printf("Data.objects[%d].cylinder.height: %f\n", i, ((t_cylinder *)tmp->object)->height);
			printf("Data.objects[%d].cylinder.color.r: %d\n", i, ((t_cylinder *)tmp->object)->color.r);
			printf("Data.objects[%d].cylinder.color.g: %d\n", i, ((t_cylinder *)tmp->object)->color.g);
			printf("Data.objects[%d].cylinder.color.b: %d\n", i, ((t_cylinder *)tmp->object)->color.b);
		}
		tmp = tmp->next;
		i++;
	}
	clear_objects();
	return (0);
}
