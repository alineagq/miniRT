/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 00:39:37 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/11/27 10:38:45 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	print_matrix(t_mat4 a)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
			printf("%f ", a.matrix[i][j++]);
		printf("\n");
		i++;
	}
}

void	init_camera(void)
{
	t_camera	*camera;
	double		theta;
	double		half_cam;
	t_vector	axis[3];

	camera = &get_data()->camera;
	if (vector_is_equal(camera->direction, create_vector(0, 1, 0)))
		camera->direction.z += 0.0001;
	else if (vector_is_equal(camera->direction, create_vector(0, -1, 0)))
		camera->direction.z += 0.0001;
	theta = camera->fov * M_PI / 180;
	half_cam = tan(theta / 2);
	camera->viewport.view_up = create_vector(0, 1, 0);
	camera->viewport.height = 1.175 * half_cam;
	camera->viewport.width = camera->viewport.height * ASPECT_RATIO;
	axis[0] = unit_vector(negate_vector(camera->direction));
	axis[1] = unit_vector(cross(camera->viewport.view_up, axis[0]));
	axis[2] = cross(axis[0], axis[1]);
	camera->viewport.horizontal = mul_scalar(axis[1], camera->viewport.width);
	camera->viewport.vertical = mul_scalar(axis[2], camera->viewport.height);
	camera->viewport.lower_left_corner = sub_vector(sub_vector(
				sub_vector(camera->direction,
					div_scalar(negate_vector(camera->viewport.horizontal), 2)),
				div_scalar(camera->viewport.vertical, 2)),
			axis[0]);
}
