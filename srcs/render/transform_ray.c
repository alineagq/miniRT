/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_ray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 13:57:39 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/11/19 14:02:22 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static void	apply_transformation_point(t_vector *pos, t_mat4 transformation)
{
	t_vector	new_pos;
	t_mat4		applied;
	t_mat4		m_point;

	m_point = point_to_matrix(*pos);
	applied = multiply_matrix(transformation, m_point);
	new_pos = create_vector(applied.matrix[0][0], applied.matrix[1][0],
			applied.matrix[2][0]);
	*pos = new_pos;
}

static void	apply_transformation_vec(t_vector *vec, t_mat4 transformation)
{
	t_vector	new_pos;
	t_mat4		applied;
	t_mat4		m_vec;

	m_vec = vec3_to_matrix(*vec);
	applied = multiply_matrix(transformation, m_vec);
	new_pos = create_vector(applied.matrix[0][0], applied.matrix[1][0],
			applied.matrix[2][0]);
	*vec = new_pos;
}

t_mat4	transform_object(t_vector translation, t_vector scale)
{
	t_mat4	transform;
	t_mat4	m_scale;
	t_mat4	m_translation;

	m_scale = scaling_matrix(scale);
	m_translation = translation_matrix(translation);
	transform = multiply_matrix(m_translation, m_scale);
	return (transform);
}

t_ray	transform_ray(t_ray ray, t_mat4 transform)
{
	t_ray	new_ray;

	new_ray = ray;
	apply_transformation_point(&new_ray.origin, transform);
	apply_transformation_vec(&new_ray.direction, transform);
	return (new_ray);
}
