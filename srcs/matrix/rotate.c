/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 21:34:28 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/11/19 21:34:59 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_mat4	rotate_x_matrix(double radians)
{
	t_mat4	a;

	a = identity_matrix();
	a.matrix[1][1] = cos(radians);
	a.matrix[1][2] = -sin(radians);
	a.matrix[2][1] = sin(radians);
	a.matrix[2][2] = cos(radians);
	return (a);
}

t_mat4	rotate_y_matrix(double radians)
{
	t_mat4	a;

	a = identity_matrix();
	a.matrix[0][0] = cos(radians);
	a.matrix[0][2] = sin(radians);
	a.matrix[2][0] = -sin(radians);
	a.matrix[2][2] = cos(radians);
	return (a);
}

t_mat4	rotate_z_matrix(double radians)
{
	t_mat4	a;

	a = identity_matrix();
	a.matrix[0][0] = cos(radians);
	a.matrix[0][1] = -sin(radians);
	a.matrix[1][0] = sin(radians);
	a.matrix[1][1] = cos(radians);
	return (a);
}
