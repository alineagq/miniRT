/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_orientation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 21:31:06 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/11/19 21:37:12 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	check_equal_vec3(t_vector a, t_vector b)
{
	int	ax_eq_bx;
	int	ay_eq_by;
	int	az_eq_bz;

	ax_eq_bx = (fabs(a.x - b.x) < M_EPSILON);
	ay_eq_by = (fabs(a.y - b.y) < M_EPSILON);
	az_eq_bz = (fabs(a.z - b.z) < M_EPSILON);
	if (ax_eq_bx && ay_eq_by && az_eq_bz)
		return (1);
	return (0);
}

static int	rotate_normalized_x(t_vector a)
{
	t_vector	positive_x;
	t_vector	negative_x;

	positive_x = create_vector(1, 0, 0);
	negative_x = create_vector(-1, 0, 0);
	if (check_equal_vec3(a, positive_x) || check_equal_vec3(a, negative_x))
		return (1);
	return (0);
}

static int	rotate_normalized_z(t_vector a)
{
	t_vector	positive_z;
	t_vector	negative_z;

	positive_z = create_vector(0, 0, 1);
	negative_z = create_vector(0, 0, -1);
	if (check_equal_vec3(a, positive_z) || check_equal_vec3(a, negative_z))
		return (1);
	return (0);
}

static t_mat4	rotate_x_y(t_vector a)
{
	t_mat4	rotation;
	t_mat4	rotation_x;
	t_mat4	rotation_y;

	rotation_x = rotate_x_matrix(M_PI / 2);
	rotation_y = rotate_y_matrix(atan(a.x / a.z));
	rotation = multiply_matrix(rotation_y, rotation_x);
	return (rotation);
}

static t_mat4	rotate_z_x(t_vector a)
{
	t_mat4	rotation;
	t_mat4	rotation_x;
	t_mat4	rotation_z;

	rotation_x = rotate_x_matrix(atan(a.z / a.y));
	rotation_z = rotate_z_matrix(atan(-a.x / a.y));
	rotation = multiply_matrix(rotation_z, rotation_x);
	return (rotation);
}

t_mat4	get_orientation(t_vector a)
{
	if (check_equal_vec3(a, create_vector(0, 1, 0)))
		return (identity_matrix());
	else if (check_equal_vec3(a, create_vector(0, -1, 0)))
		return (rotate_x_matrix(M_PI));
	else if (rotate_normalized_x(a))
		return (rotate_z_matrix(M_PI / 2));
	else if (rotate_normalized_z(a))
		return (rotate_x_matrix(M_PI / 2));
	if ((fabs(a.y) < M_EPSILON))
		return (rotate_x_y(a));
	else
		return (rotate_z_x(a));
}
