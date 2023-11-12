/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:51:03 by fsuomins          #+#    #+#             */
/*   Updated: 2023/11/12 13:18:01 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static int	build_plane(t_object *plane)
{
	t_plane	*plane_data;

	plane_data = (t_plane *)plane->object;
	plane->diffuse = plane_data->color;
	plane->volume.active = 0;
	return (1);
}

static int	build_sphere(t_object *sphere)
{
	t_sphere	*sphere_data;

	sphere_data = (t_sphere *)sphere->object;
	create_box(&sphere->volume);
	sphere->diffuse = sphere_data->color;
	sphere->volume.min = vec_sub_scalar(sphere_data->origin,
			sphere_data->radius);
	sphere->volume.max = vec_add_scalar(sphere_data->origin,
			sphere_data->radius);
	return (1);
}

static int	build_cylinder(t_object *cylinder_data)
{
	t_cylinder	*cylinder;
	t_vector	inverter;
	t_vector	center_circle;

	cylinder = (t_cylinder *)cylinder_data->object;
	cylinder_data->diffuse = cylinder->color;
	cylinder->half_height = cylinder->height / 2;
	cylinder->middle = vec_mult_scalar(cylinder->direction, cylinder->height
			/ 2);
	cylinder->top = vec_add(cylinder->origin, cylinder->middle);
	cylinder->bottom = vec_sub(cylinder->origin, cylinder->middle);
	cylinder->diff = vec_sub(cylinder->top, cylinder->bottom);
	inverter = vec_sub((t_vector){1.0, 1.0, 1.0},
			vec_div_scalar(vec_mult(cylinder->diff, cylinder->diff),
				vec_dot(cylinder->diff, cylinder->diff)));
	center_circle = (t_vector){cylinder->radius * sqrt(inverter.x),
		cylinder->radius * sqrt(inverter.y), cylinder->radius
		* sqrt(inverter.z)};
	create_box(&cylinder_data->volume);
	box_add_vec(&cylinder_data->volume, vec_add(cylinder->top, center_circle));
	box_add_vec(&cylinder_data->volume, vec_sub(cylinder->top, center_circle));
	box_add_vec(&cylinder_data->volume, vec_add(cylinder->bottom,
			center_circle));
	box_add_vec(&cylinder_data->volume, vec_sub(cylinder->bottom,
			center_circle));
	return (1);
}

int	build_objects(void)
{
	t_object	*current;

	current = get_data()->objects;
	printf("build_objects\n");
	while (current)
	{
		if (current->id == SPHERE)
			build_sphere(current);
		else if (current->id == PLANE)
			build_plane(current);
		else if (current->id == CYLINDER)
			build_cylinder(current);
		current = current->next;
	}
	return (1);
}
