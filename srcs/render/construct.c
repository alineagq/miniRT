/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:51:03 by fsuomins          #+#    #+#             */
/*   Updated: 2023/11/09 10:39:00 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_vector	vec_sub_scalar(t_vector vec, double scalar)
{
	t_vector	result;

	result.x = vec.x - scalar;
	result.y = vec.y - scalar;
	result.z = vec.z - scalar;
	return (result);
}

t_vector	vec_add_scalar(t_vector vec, double scalar)
{
	t_vector	result;

	result.x = vec.x + scalar;
	result.y = vec.y + scalar;
	result.z = vec.z + scalar;
	return (result);
}

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
