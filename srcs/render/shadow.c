/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:47:20 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/11/21 00:29:51 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_ray	ray(t_vector origin, t_vector direction)
{
	return ((t_ray){origin, direction});
}

static t_ray	get_light_ray(t_light light, t_vector point)
{
	t_vector	light_v;
	t_vector	direction;
	t_ray		light_ray;

	light_v = sub_vector(light.origin, point);
	direction = unit_vector(light_v);
	light_ray = ray(point, direction);
	return (light_ray);
}

double	get_light_t(t_light light, t_vector point)
{
	t_vector	light_v;
	double		light_t;

	light_v = sub_vector(light.origin, point);
	light_t = length(&light_v);
	return (light_t);
}

int	is_shadowed(t_vector point)
{
	double		distance;
	t_ray		light_ray;
	t_intersect	*intersections;
	t_intersect	*closest;
	t_light		*light;

	light = &get_data()->light;
	distance = get_light_t(*light, point);
	light_ray = get_light_ray(*light, point);
	intersections = calculate_intersection(light_ray, get_data()->objects);
	closest = hit(intersections);
	if (closest && closest->id < distance)
	{
		clear_intersect(&intersections);
		return (1);
	}
	clear_intersect(&intersections);
	return (0);
}
