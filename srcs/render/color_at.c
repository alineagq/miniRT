/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_at.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 13:37:59 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/11/22 10:19:26 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_intersect	*hit(t_intersect *intersections)
{
	while (intersections)
	{
		if (intersections->id >= 0)
			return (intersections);
		intersections = intersections->next;
	}
	return (NULL);
}

t_vector	position(t_ray ray, double t)
{
	return (add_vector(ray.origin, mul_scalar(ray.direction, t)));
}

static t_comps	prepare_computations(t_intersect *intersects, t_ray ray)
{
	t_comps		comps;
	t_intersect	*closest;

	closest = hit(intersects);
	comps.t = closest->id;
	comps.point = position(ray, closest->id);
	comps.eyev = mul_scalar(ray.direction, -1);
	comps.normalv = normal_at(closest->object, comps.point);
	comps.object = closest->object;
	if (dot(comps.normalv, comps.eyev) < 0)
	{
		comps.inside = 1;
		comps.normalv = mul_scalar(comps.normalv, -1);
	}
	else
		comps.inside = 0;
	comps.over_point = add_vector(comps.point, mul_scalar(comps.normalv, M_EPSILON));
	return (comps);
}

t_vector	ray_color(t_ray ray)
{
	t_vector	color;
	t_comps		comps;
	t_intersect	*intersects;

	intersects = calculate_intersection(ray, get_data()->objects);
	if (intersects == NULL || hit(intersects) == NULL)
	{
		clear_intersect(&intersects);
		return ((t_vector){0, 0, 0});
	}
	comps = prepare_computations(intersects, ray);
	clear_intersect(&intersects);
	color = shade_hit(comps);
	return (color);
}
