/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:39:08 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/11/14 11:09:27 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_vector	mat_get(t_mat4 mx, t_mat_element type)
{
	if (type == m_right)
		return ((t_vector){mx.data[0][0], mx.data[0][1], mx.data[0][2]});
	if (type == m_up)
		return ((t_vector){mx.data[1][0], mx.data[1][1], mx.data[1][2]});
	if (type == m_forward)
		return ((t_vector){mx.data[2][0], mx.data[2][1], mx.data[2][2]});
	if (type == m_origin)
		return ((t_vector){mx.data[3][0], mx.data[3][1], mx.data[3][2]});
	return ((t_vector){0, 0, 0});
}

int	camera_ray(t_data *scene, t_ray *ray, int u, int v)
{
	t_vector	worldwide;

	worldwide.x = (2 * ((u + 0.5) / scene->mlx.image->width) - 1)
		* scene->camera.view_range * scene->ratio;
	worldwide.y = (1 - 2 * ((v + 0.5) / scene->mlx.image->height)
			* scene->camera.view_range);
	worldwide.z = 1;
	ray->origin = mat_get(scene->camera.world, m_origin);
	ray->direction = vec_unit(mat4_mult_dir(scene->camera.world, worldwide));
	ray->max = INFINITY;
	return (1);
}

int	render(void)
{
	t_data	*scene;
	t_color	color;
	t_ray	ray;

	scene = get_data();
	scene->u = 0;
	scene->v = 0;
	while (scene->u < (int)scene->mlx.image->width)
	{
		while (scene->v < (int)scene->mlx.image->height)
		{
			camera_ray(scene, &ray, scene->u, scene->v);
			color = ray_color(&ray);
			if (color.r || color.g || color.b)
				printf("color: %d %d %d\n", color.r, color.g, color.b);
			write_color(&scene->mlx.image, scene->u, scene->v, color);
			scene->v++;
		}
		scene->u++;
	}
	return (1);
}
