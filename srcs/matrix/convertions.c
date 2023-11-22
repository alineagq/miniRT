/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 01:31:20 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/11/19 01:32:12 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_mat4	point_to_matrix(t_vector point)
{
	t_mat4	a;

	a.rows = 4;
	a.cols = 1;
	a.matrix[0][0] = point.x;
	a.matrix[1][0] = point.y;
	a.matrix[2][0] = point.z;
	a.matrix[3][0] = 1;
	return (a);
}

t_mat4	vec3_to_matrix(t_vector vec)
{
	t_mat4	a;

	a.rows = 4;
	a.cols = 1;
	a.matrix[0][0] = vec.x;
	a.matrix[1][0] = vec.y;
	a.matrix[2][0] = vec.z;
	a.matrix[3][0] = 0;
	return (a);
}

t_vector	matrix_to_point(t_mat4 a)
{
	t_vector	point;

	point.x = a.matrix[0][0];
	point.y = a.matrix[1][0];
	point.z = a.matrix[2][0];
	return (point);
}
