/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:08:29 by fsuomins          #+#    #+#             */
/*   Updated: 2023/11/27 10:15:27 by aqueiroz         ###   ########.fr       */
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

static void	print_objects(void)
{
	t_object	*object;

	object = get_data()->objects;
	while (object)
	{
		if (object->id == SPHERE)
		{
			t_sphere	*sphere;

			sphere = object->object;
			printf("sphere:\n");
			printf("sphere->origin: %f, %f, %f\n", sphere->origin.x,
				sphere->origin.y, sphere->origin.z);
			printf("sphere->radius: %f\n", sphere->radius);
			printf("sphere->color: %f, %f, %f\n", sphere->color.x,
				sphere->color.y, sphere->color.z);
			printf("sphere->diameter: %f\n", sphere->diameter);
			printf("sphere->center: ");
			print_t_vector(sphere->center);
			printf("sphere->transform:\n");
			print_matrix(sphere->transform);
			printf("sphere->invert:\n");
			print_matrix(sphere->invert);
			
		}
		else if (object->id == PLANE)
		{
			t_plane	*plane;

			plane = object->object;
			printf("plane:\n");
			printf("plane->origin: %f, %f, %f\n", plane->origin.x,
				plane->origin.y, plane->origin.z);
			printf("plane->direction: %f, %f, %f\n", plane->direction.x,
				plane->direction.y, plane->direction.z);
			printf("plane->color: %f, %f, %f\n", plane->color.x,
				plane->color.y, plane->color.z);
		}
		else if (object->id == CYLINDER)
		{
			t_cylinder	*cylinder;

			cylinder = object->object;
			printf("cylinder:\n");
			printf("cylinder->origin: %f, %f, %f\n", cylinder->origin.x,
				cylinder->origin.y, cylinder->origin.z);
			printf("cylinder->direction: %f, %f, %f\n", cylinder->direction.x,
				cylinder->direction.y, cylinder->direction.z);
			printf("cylinder->color: %f, %f, %f\n", cylinder->color.x,
				cylinder->color.y, cylinder->color.z);
			printf("cylinder->diameter: %f\n", cylinder->diameter);
			printf("cylinder->height: %f\n", cylinder->height);
		}
		object = object->next;
	}
	
}

static void	print_all_data(void)
{
	t_data	*data;

	data = get_data();
	printf("mlx settings:\n");
	printf("mlx->mlx_ptr: %p\n", data->mlx.mlx);
	printf("mlx->img_ptr: %p\n", data->mlx.image);
	printf("mlx->width: %d\n", data->mlx.width);
	printf("mlx->height: %d\n", data->mlx.height);

	printf("camera settings:\n");
	printf("camera->fov: %f\n", data->camera.fov);
	printf("camera->origin: %f, %f, %f\n", data->camera.origin.x,
		data->camera.origin.y, data->camera.origin.z);
	printf("camera->direction: %f, %f, %f\n", data->camera.direction.x,
		data->camera.direction.y, data->camera.direction.z);
	
	printf("viewport: \n");
	printf("camera->viewport_width: %f\n", data->camera.viewport.width);
	printf("camera->viewport_height: %f\n", data->camera.viewport.height);
	printf("camera->viewport_distance: %f\n", data->camera.viewport.pixel_size);
	printf("viewport transforme matrix\n");
	print_matrix(data->camera.viewport.transform);
	print_matrix(data->camera.viewport.inverse);
	
	printf("ambient light settings:\n");

	printf("ambient->ratio: %f\n", data->ambient.ratio);
	printf("ambient->color: %f, %f, %f\n", data->ambient.color.x,
		data->ambient.color.y, data->ambient.color.z);
	
	printf("lihgt settings:\n");
	printf("light->origin: %f, %f, %f\n", data->light.origin.x,
		data->light.origin.y, data->light.origin.z);
	printf("light->ratio: %f\n", data->light.ratio);
	printf("light->color: %f, %f, %f\n", data->light.color.x,
		data->light.color.y, data->light.color.z);

	printf("objects settings:\n");

	print_objects();
}

int	main(int argc, char **argv)
{
	print_header();
	validate_args(argc, argv);
	init_camera();
	init_objects();
	init_resolution();
	// print_all_data();
	render();
	window_loop();
	clear_objects();
	return (0);
}
