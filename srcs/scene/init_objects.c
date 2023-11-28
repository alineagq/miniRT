/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:23:52 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/11/27 10:14:56 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	init_sphere(t_sphere *sphere)
{
	t_vector	radius_vector;

	sphere->center = create_vector(0, 0, 0);
	sphere->material = default_material(sphere->color);
	radius_vector = create_vector(sphere->radius, sphere->radius,
		sphere->radius);
	sphere->transform = transform_object(sphere->origin, radius_vector);
	sphere->invert = inverse_matrix(sphere->transform);
}

void	init_plane(t_plane *plane)
{
	plane->transform = identity_matrix();
	plane->material = default_material(plane->color);
	plane->transform = transform_cy_pl(plane->direction, plane->origin,
		plane->transform);
	plane->invert = inverse_matrix(plane->transform);
}

void	init_cylinder(t_cylinder *cy)
{
	t_mat4		transform_matrix;
	t_vector	radius_vector;

	cy->min = -(cy->height / 2);
	cy->max = cy->height / 2;
	cy->transform = identity_matrix();
	cy->material = default_material(cy->color);
	cy->top = add_vector(cy->origin, mul_scalar(cy->direction, cy->height
			/ 2.0));
	cy->bottom = add_vector(cy->origin, mul_scalar(cy->direction, -(cy->height
				/ 2.0)));
	radius_vector = create_vector(cy->radius, cy->radius, cy->radius);
	transform_matrix = scaling_matrix(radius_vector);
	cy->transform = transform_cy_pl(cy->direction, cy->origin,
		transform_matrix);
	cy->invert = inverse_matrix(cy->transform);
}

void	init_objects(void)
{
	t_object	*object;

	object = get_data()->objects;
	while (object)
	{
		if (object->id == SPHERE)
			init_sphere(object->object);
		else if (object->id == PLANE)
			init_plane(object->object);
		else if (object->id == CYLINDER)
			init_cylinder(object->object);
		object = object->next;
	}
}
