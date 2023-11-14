/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shede.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:55:57 by fsuomins          #+#    #+#             */
/*   Updated: 2023/11/14 11:20:56 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_vector	rgb_to_vector(t_color color)
{
	return ((t_vector){(double)color.r, (double)color.g, (double)color.b});
}

t_vector	flat_shade(t_hit *hit)
{
	t_vector	color;
	double		scalar;

	color = (t_vector){0, 0, 0};
	scalar = 0.0;
	if (!vec_comp_scalar(hit->normal, 0.0))
	{
		color = (t_vector){sin(hit->normal.x * 2.5) * 0.5 + 0.5,
			sin(hit->normal.y * 2.5 + 2.0) * 0.5 + 0.5, sin(hit->normal.z * 2.5
				+ 4.0) * 0.5 + 0.5};
		scalar = vec_magintude(color) * 0.5773502692;
	}
	color = vec_mult(rgb_to_vector(hit->color), (t_vector){scalar, scalar,
			scalar});
	return (vec_clamp(color, 0.0, 1.0));
}


int	is_shadow(t_vector origin, t_vector dir)
{
	t_hit	shadow;

	ft_memset(&shadow, 0, sizeof(t_hit));
	shadow.ray.direction = vec_unit(dir);
	shadow.ray.origin = vec_add(origin, vec_mult_scalar(shadow.ray.direction,
				M_EPSILON));
	shadow.ray.max = M_INFINITY;
	shadow.distance = M_INFINITY;
	intersect(&shadow);
	if (shadow.distance > vec_magintude(dir))
		return (false);
	return (true);
}

t_vector	s_shaded(t_data *scene, t_hit *rec)
{
	t_vector	l_diffuse;
	t_light		lights;

	lights = scene->light;
	l_diffuse = vec_mult(rgb_to_vector(rec->color),
			rgb_to_vector(scene->ambient.color));
	lights.dir = vec_sub_scalar(lights.origin, rec->point);
	if (is_shadow(scene) == 0)
	{
		lights.angle = clamp(vec_dot(vec_unit(lights.dir), rec->normal), 0,
				1);
		l_diffuse = vec_add(l_diffuse, vec_mult_scalar(lights->color,
					lights.angle));
	}
	return (vec_clamp(vec_mult(rec->color, l_diffuse), 0.0, 1.0));
}

t_vector	shaded_shade(t_hit *hit)
{
	t_vector	color;
	t_vector	light_dir;
	t_vector	light_color;
	double		diffuse;

	color = (t_vector){0, 0, 0};
	light_dir = vec_unit(vec_sub((t_vector){0, 0, 0}, hit->point));
	light_color = (t_vector){1, 1, 1};
	diffuse = vec_dot(light_dir, hit->normal);
	if (diffuse > 0)
	{
		color = vec_mult(rgb_to_vector(hit->color), light_color);
		color = vec_mult_scalar(color, diffuse);
	}
	return (vec_clamp(color, 0.0, 1.0));
}

t_vector	shade(t_hit *hit)
{
	t_vector	color;

	color = (t_vector){0, 0, 0};
	if (get_data()->viewport == flat)
		color = flat_shade(hit);
	if (get_data()->viewport == aabb)
		color = s_aabb(hit);
	printf("color: %f %f %f\n", color.x, color.y, color.z);
	if (get_data()->viewport == shaded)
		color = shaded_shade(hit);
	return (color);
}
