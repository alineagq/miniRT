/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:08:07 by fsuomins          #+#    #+#             */
/*   Updated: 2024/03/16 15:17:40 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	print_sphere(t_sphere *sphere)
{
	printf(" ________________________________________________");
	printf("sphere:\n");
	printf("\torigin: %f, %f, %f\n", sphere->center.x, sphere->center.y,
		sphere->center.z);
	printf("\tradius: %f\n", sphere->radius);
	printf("\tcolor: %f, %f, %f\n", sphere->material.color.x,
		sphere->material.color.y, sphere->material.color.z);
}

void	print_plane(t_plane *plane)
{
	printf(" _________________________________________________");
	printf("plane:\n");
	printf("\torigin: %f, %f, %f\n", plane->position.x, plane->position.y,
		plane->position.z);
	printf("\tdirection: %f, %f, %f\n", plane->normal.x, plane->normal.y,
		plane->normal.z);
	printf("\tcolor: %f, %f, %f\n", plane->material.color.x,
		plane->material.color.y, plane->material.color.z);
}

void	print_cylinder(t_cylinder *cylinder)
{
	printf(" ______________________________________________");
	printf("cylinder:\n");
	printf("\torigin: %f, %f, %f\n", cylinder->center.x, cylinder->center.y,
		cylinder->center.z);
	printf("\tdirection: %f, %f, %f\n", cylinder->axis.x, cylinder->axis.y,
		cylinder->axis.z);
	printf("\tcolor: %f, %f, %f\n", cylinder->material.color.x,
		cylinder->material.color.y, cylinder->material.color.z);
	printf("\tradius: %f\n", cylinder->radius);
	printf("\theight: %f\n", cylinder->height);
	printf("\tcap_top: %f %f %f\n", cylinder->cap_top.x, cylinder->cap_top.y,
		cylinder->cap_top.z);
	printf("\tcap_bottom: %f %f %f\n", cylinder->cap_bottom.x,
		cylinder->cap_bottom.y, cylinder->cap_bottom.z);
}

void	print_objects(void)
{
	t_object	*object;

	object = get_data()->objects;
	while (object)
	{
		if (object->shape == SPHERE)
			print_sphere(object->sphere);
		else if (object->shape == PLANE)
			print_plane(object->plane);
		else if (object->shape == CYLINDER)
			print_cylinder(object->cyl);

		object = object->next;
	}
}

void	print_data(void)
{
	t_data	*data;

	data = get_data();
	printf(" ________________________________________________");
	printf("camera_\n");
	printf("\tPosition: %f %f %f\n", data->camera.origin.x,
		data->camera.origin.y, data->camera.origin.z);
	printf("\tDirection: %f %f %f\n", data->camera.direction.x,
		data->camera.direction.y, data->camera.direction.z);
	printf("\tFOV: %f\n", data->camera.fov);
	printf(" _________________________________________");
	printf("ambient_light_\n");
	printf("\tRatio: %f\n", data->ambient.ratio);
	printf("\tColor: %f %f %f\n", data->ambient.color.x, data->ambient.color.y,
		data->ambient.color.z);
	printf(" _________________________________________________");
	printf("light_\n");
	printf("\tOrigin: %f %f %f\n", data->light.origin.x, data->light.origin.y,
		data->light.origin.z);
	printf("\tRatio: %f\n", data->light.ratio);
	printf("\tColor: %f %f %f\n", data->light.color.x, data->light.color.y,
		data->light.color.z);
	print_objects();
}
