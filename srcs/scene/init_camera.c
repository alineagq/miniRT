/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 00:39:37 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/11/22 19:39:47 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_vector	get_look_up(t_vector direction)
{
	t_vector	look_up;
	double		dot_up;

	look_up = create_vector(0, 1, 0);
	dot_up = dot(direction, look_up);
	if (fabs(dot_up - 1) < M_EPSILON)
		look_up = create_vector(1, 0, 0);
	else if (fabs(dot_up - (-1)) < M_EPSILON)
		look_up = create_vector(-1, 0, 0);
	return (look_up);
}

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

void	set_pixel_size(void)
{
	double		half_view;

	get_data()->camera.fov = get_data()->camera.fov / 180 * M_PI;
	half_view = tan(get_data()->camera.fov / 2);
	get_data()->camera.viewport.width = half_view * ASPECT_RATIO;
	get_data()->camera.viewport.height = half_view;
	if (ASPECT_RATIO >= 1)
	{
		get_data()->camera.viewport.width = half_view;
		get_data()->camera.viewport.height = half_view / ASPECT_RATIO;
	}
	get_data()->camera.viewport.pixel_size = (get_data()->camera.viewport.width * 2) / WIDTH;
}

void	init_camera(void)
{
	t_camera	*camera;
	t_vector	look_up;

	camera = &get_data()->camera;
	set_pixel_size();
	look_up = get_look_up(camera->direction);
	camera->viewport.transform = view_transform(camera->origin,
			camera->direction, look_up);
	camera->viewport.inverse = inverse_matrix(camera->viewport.transform);
	
}
