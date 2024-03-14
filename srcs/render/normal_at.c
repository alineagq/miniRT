/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:23:21 by aqueiroz          #+#    #+#             */
/*   Updated: 2024/03/13 20:10:51 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static t_vector	local_normal_cylinder(t_cylinder *cylinder,
		t_vector local_point)
{
	double	distance;

	distance = local_point.x * local_point.x + local_point.z * local_point.z;
	if (distance < 1 && local_point.y >= -(cylinder->height / 2) - M_EPSILON)
		return (create_vector(0, 1, 0));
	else if (distance < 1 && local_point.y <= (cylinder->height / 2) + M_EPSILON)
		return (create_vector(0, -1, 0));
	else
		return (create_vector(local_point.x, 0, local_point.z));
}

t_vector	local_normal_at(t_hit *object, t_vector local_point)
{
	if (object->id == SPHERE)
		return (sub_vector(local_point, create_vector(0, 0, 0)));
	else if (object->id == CYLINDER)
		return (local_normal_cylinder(object->object, local_point));
	else
		return (create_vector(0, 1, 0));
}

t_vector	get_object_vector(t_mat4 inv_matrix, t_vector world_point)
{
	t_vector	object_vector;
	t_mat4		world_point_matrix;
	t_mat4		inv_by_world_point;

	world_point_matrix = point_to_matrix(world_point);
	inv_by_world_point = multiply_matrix(inv_matrix, world_point_matrix);
	object_vector = matrix_to_point(inv_by_world_point);
	return (object_vector);
}

t_vector	get_world_normal(t_mat4 inv_matrix, t_mat4 normal_as_matrix)
{
	t_mat4		transposed_matrix;
	t_mat4		transpose_by_normal;
	t_vector	world_normal;

	transposed_matrix = transpose_matrix(inv_matrix);
	transpose_by_normal = multiply_matrix(transposed_matrix, normal_as_matrix);
	world_normal = matrix_to_point(transpose_by_normal);
	return (world_normal);
}

t_vector	normal_at(t_hit *object, t_vector world_point)
{
	t_mat4		inv_matrix;
	t_vector	world_normal;
	t_vector	object_vector;
	t_vector	object_normal;
	t_mat4		normal_as_matrix;

	inv_matrix = get_inv_transform(object);
	object_vector = get_object_vector(inv_matrix, world_point);
	object_normal = local_normal_at(object, object_vector);
	normal_as_matrix = point_to_matrix(object_normal);
	world_normal = get_world_normal(inv_matrix, normal_as_matrix);
	return (unit_vector(world_normal));
}
