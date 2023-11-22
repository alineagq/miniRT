/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:00:51 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/11/19 14:01:29 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_mat4	translation_matrix(t_vector x)
{
	t_mat4	a;

	a = identity_matrix();
	a.matrix[0][3] = x.x;
	a.matrix[1][3] = x.y;
	a.matrix[2][3] = x.z;
	return (a);
}

t_mat4	scaling_matrix(t_vector x)
{
	t_mat4	a;

	a = identity_matrix();
	a.matrix[0][0] = x.x;
	a.matrix[1][1] = x.y;
	a.matrix[2][2] = x.z;
	return (a);
}

t_mat4	shearing_matrix(t_vector p1, t_vector p2)
{
	t_mat4	a;

	a = identity_matrix();
	a.matrix[0][1] = p1.x;
	a.matrix[0][2] = p2.x;
	a.matrix[1][0] = p1.y;
	a.matrix[1][2] = p2.y;
	a.matrix[2][0] = p1.z;
	a.matrix[2][1] = p2.z;
	return (a);
}
