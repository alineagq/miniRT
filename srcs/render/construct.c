/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:51:03 by fsuomins          #+#    #+#             */
/*   Updated: 2023/11/09 19:04:26 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	create_box(t_aabb *box)
{
	t_vector	max;
	t_vector	min;

	max = {M_INFINITY, M_INFINITY, M_INFINITY};
	min = {-M_INFINITY, -M_INFINITY, -M_INFINITY};
	box->min = min;
	box->max = max;
	return (1);
}

int	build_plane(t_object *plane)
{
	t_plane	*plane_data;

	plane_data = (t_plane *)plane->object;
	create_box(&plane->volume);
	plane->volume.min = vec_sub_scalar(plane_data->origin, M_INFINITY);
	plane->volume.max = vec_add_scalar(plane_data->origin, M_INFINITY);
	return (1);
}

int	build_cylinder(t_object *cylinder)
{
	t_cylinder	*cy_data;
	t_vector	inverted;
	t_vector	center;

	cy_data = (t_cylinder *)cylinder->object;
	cy_data->height_d2 = cy_data->height / 2;
	cy_data->half_height = vec_mult_scalar(cy_data->orientation,
			cy_data->height_d2);
	cy_data->top = vec_add(cy_data->origin, cy_data->half_height);
	cy_data->bottom = vec_sub(cy_data->origin, cy_data->half_height);
	cy_data->diff = vec_sub(cy_data->top, cy_data->bottom);
	// TODO: check if this is correct
}

int	build_sphere(t_object *sphere)
{
	t_sphere	*sphere_data;

	sphere_data = (t_sphere *)sphere->object;
	create_box(&sphere->volume);
	sphere->volume.min = vec_sub_scalar(sphere_data->origin,
			sphere_data->radius);
	sphere->volume.max = vec_add_scalar(sphere_data->origin,
			sphere_data->radius);
	return (1);
}

int	build_objects(void)
{
	t_object	*current;

	current = get_data()->objects;
	while (current)
	{
		if (current->id == SPHERE)
			build_sphere(current);
		// else if (current->id == PLANE)
		// 	build_plane(current);
		// else if (current->id == CYLINDER)
		// 	build_cylinder(current);
		current = current->next;
	}
	return (1);
}
