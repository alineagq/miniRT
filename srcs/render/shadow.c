/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:47:20 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/11/22 18:15:02 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_ray	ray(t_vector origin, t_vector direction)
{
	return ((t_ray){origin, direction});
}

t_vector	s_multiply(t_vector a, double n)
{
	return ((t_vector){a.x * n, a.y * n, a.z * n});
}

t_vector	s_division(t_vector a, double n)
{
	return (s_multiply(a, 1 / n));
}

double	length_square(t_vector a)
{
	return (a.x * a.x + a.y * a.y + a.z * a.z);
}

double	magnitude(t_vector a)
{
	return (sqrt(length_square(a)));
}

t_vector	normalize(t_vector a)
{
	return (s_division(a, magnitude(a)));
}

static t_ray	get_light_ray(t_light light, t_vector point)
{
	t_vector	light_v;
	t_vector	direction;
	t_ray	light_ray;

	light_v = sub_vector(light.origin, point);
	direction = normalize(light_v);
	light_ray = ray(point, direction);
	return (light_ray);
}

double	get_light_t(t_light light, t_vector point)
{
	t_vector	light_v;
	double	light_t;

	light_v = sub_vector(light.origin, point);
	light_t = magnitude(light_v);
	return (light_t);
}

int	is_shadowed(t_vector point)
{
	double			distance;
	t_ray			light_ray;
	t_intersect	*intersections;
	t_intersect	*closest_intersection;

	distance = get_light_t(get_data()->light, point);
	light_ray = get_light_ray(get_data()->light, point);
	intersections = calculate_intersection(light_ray, get_data()->objects);
	closest_intersection = hit(intersections);
	if (closest_intersection && closest_intersection->id < distance)
	{
		clear_intersect(&intersections);
		return (1);
	}
	clear_intersect(&intersections);
	return (0);
}
