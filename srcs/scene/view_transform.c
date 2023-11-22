/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_transform.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 23:24:42 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/11/20 20:57:12 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static void	set_values_on_given_col(t_mat4 *matrix, int col, t_vector v)
{
	matrix->matrix[col][0] = v.x;
	matrix->matrix[col][1] = v.y;
	matrix->matrix[col][2] = v.z;
}

t_mat4	view_transform(t_vector from, t_vector forward, t_vector up)
{
	t_vector	left;
	t_vector	true_up;
	t_vector	negated_vec;
	t_mat4		orientation;
	t_mat4		translation;

	negated_vec = mul_scalar(from, -1);
	orientation = identity_matrix();
	left = cross(forward, unit_vector(up));
	true_up = cross(left, forward);
	set_values_on_given_col(&orientation, 0, left);
	set_values_on_given_col(&orientation, 1, true_up);
	set_values_on_given_col(&orientation, 2, mul_scalar(forward, -1));
	translation = translation_matrix(negated_vec);
	return (multiply_matrix(orientation, translation));
}
