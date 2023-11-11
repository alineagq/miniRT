/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:39:08 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/11/10 22:07:17 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	tracing(t_data *scene, t_ray ray, t_color *color)
{
	t_hit	hit;

	(void)scene;
	ft_memset(&hit, 0, sizeof(t_hit));
	hit.ray = ray;
	hit.distance = INFINITY;
	hit.ray.max = INFINITY;
	*color = (t_color){0, 0, 0};
	if (intersect(&hit))
	{
		hit.color = hit.obj->diffuse;
		*color = hit.color;
	}
	return (0);
}

t_vector	mat4_get(t_mat4 mx, t_mat_element type)
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
	ray->origin = mat4_get(scene->camera.world, m_origin);
	ray->direction = vec_unit(mat4_mult_dir(scene->camera.world, worldwide));
	ray->max = INFINITY;
	return (1);
}

unsigned int	rgb_to_data(const t_color color)
{
	int		r;
	int		g;
	int		b;

	r = (double)(color.r * 255);
	g = (double)(color.g * 255);
	b = (double)(color.b * 255);
	return (r << 16 | g << 8 | b);
}

void	calculate_color(mlx_image_t **image, int u, int v, t_color color)
{
	mlx_put_pixel(*image, u, v, rgb_to_data(color));
}

int	render(t_data *scene)
{
	t_color	color;
	t_ray	ray;

	scene->u = 0;
	scene->v = 0;
	while (scene->u < (int)scene->mlx.image->width)
	{
		while (scene->v < (int)scene->mlx.image->height)
		{
			camera_ray(scene, &ray, scene->u, scene->v);
			tracing(scene, ray, &color);
			calculate_color(&scene->mlx.image, scene->u, scene->v, color);
			scene->v++;
		}
		scene->u++;
	}
	return (1);
}
