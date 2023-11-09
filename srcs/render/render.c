/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:39:08 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/11/09 11:20:53 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_vector	mat4_get(t_mat4 m4, t_mat_element get)
{
	if (get == m_right)
		return ((t_vector){m4.data[0][0], m4.data[0][1], m4.data[0][2]});
	if (get == m_up)
		return ((t_vector){m4.data[1][0], m4.data[1][1], m4.data[1][2]});
	if (get == m_forward)
		return ((t_vector){m4.data[2][0], m4.data[2][1], m4.data[2][2]});
	if (get == m_origin)
		return ((t_vector){m4.data[3][0], m4.data[3][1], m4.data[3][2]});
	return ((t_vector){0.0, 0.0, 0.0});
}

t_vector	mat4_multi_direction(t_mat4 cam_world, t_vector world)
{
	t_vector	new;

	new.x = world.x *cam_world.data[0][0] + world.y *cam_world.data[1][0]
		+ world.z *cam_world.data[2][0];
	new.y = world.x *cam_world.data[0][1] + world.y *cam_world.data[1][1]
		+ world.z *cam_world.data[2][1];
	new.z = world.x *cam_world.data[0][2] + world.y *cam_world.data[1][2]
		+ world.z *cam_world.data[2][2];
	return (new);
}

t_vector	vec_unit(t_vector v)
{
	double	len;

	len = vec_len(v);
	return ((t_vector){v.x / len, v.y / len, v.z / len});
}

int	camera_init(t_ray *ray)
{
	t_vector	world;
	t_data		*data;

	data = get_data();
	world.x = (2 * ((data->u + 0.5) / data->mlx.width) - 1);
	world.x *= data->camera.view_range * data->camera.fov;
	world.y = (1 - 2 * ((data->v + 0.5) / data->mlx.height));
	world.y *= data->camera.view_range;
	world.z = 1;
	ray->origin = mat4_get(data->camera.world, m_origin);
	ray->direction = vec_unit(mat4_multi_direction(data->camera.world, world));
	ray->max = INFINITY;
	return (1);
}

int	hit_sphere(t_object )

int	tracer(t_ray ray, t_color *color)
{
	t_data	*data;
	t_hit	hit;

	data = get_data();
	ft_memset(&hit, 0, sizeof(t_hit));
	hit.ray = ray;
	hit.distance = INFINITY;
	hit.ray.max = INFINITY;
	*color = (t_color){0, 0, 0};
	if (hit_sphere(data->objects, &hit))
	{
		hit.color = hit.ref->diffuse;
		*color = shade(&hit);
		hit.ref == NULL;
		return (1);
	}
	else if (data->viewport == aabb && hit.aabb_hit)
		*color = render_aabb(&hit);
	hit.ref = NULL;
	return (0);
}

int	render(void)
{
	t_color	color;
	t_ray	ray;
	t_data	*data;

	data = get_data();
	data->u = 0;
	data->v = 0;
	while (data->u < data->buffer.width)
	{
		while (data->v < data->buffer.height)
		{
			camera_init(&ray);
			tracer(ray, &color);
			print_color(&data->buffer, data->u, data->v, color);
			data->v++;
		}
		data->v = 0;
		data->u++;
	}
	return (1);
}
