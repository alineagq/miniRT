/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 21:55:14 by fsuomins          #+#    #+#             */
/*   Updated: 2023/11/09 23:42:14 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_mat4	mat4_identity(void)
{
	t_mat4	identity;
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
			identity.data[i][j++] = 0;
		i++;
	}
	identity.data[0][0] = 1;
	identity.data[1][1] = 1;
	identity.data[2][2] = 1;
	identity.data[3][3] = 1;
	return (identity);
}

t_mat4	camera_show(t_vector origem, t_vector focus)
{
	t_vector	up;
	t_vector	right;
	t_vector	forward;
	t_mat4		rotation;

	forward = vec_normalize(vec_sub(focus, origem));
	right = vec_normalize(vec_cross(forward, (t_vector){0, 1, 0}));
	up = vec_normalize(vec_cross(right, forward));
	rotation = mat4_identity();
	rotation.data[0][0] = right.x;
	rotation.data[0][1] = right.y;
	rotation.data[0][2] = right.z;
	rotation.data[1][0] = up.x;
	rotation.data[1][1] = up.y;
	rotation.data[1][2] = up.z;
	rotation.data[2][0] = forward.x;
	rotation.data[2][1] = forward.y;
	rotation.data[2][2] = forward.z;
	return (rotation);
}

t_vector	mat4_mult_dir(t_mat4 matrix, t_vector dir)
{
	t_vector	new;

	new.x = dir.x * matrix.data[0][0] + dir.y
		* matrix.data[1][0] + dir.z * matrix.data[2][0];
	new.y = dir.x * matrix.data[0][1] + dir.y
		* matrix.data[1][1] + dir.z * matrix.data[2][1];
	new.z = dir.x * matrix.data[0][2] + dir.y
		* matrix.data[1][2] + dir.z * matrix.data[2][2];
	return (new);
}
