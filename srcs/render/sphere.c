/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 00:26:27 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/11/10 01:05:20 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static int	sphere_hit(t_object *object, t_hit *hit, double t, int inside)
{
	t_sphere	*sphere;

	sphere = object->object;
	hit->obj = object;
	hit->distance = t;
	hit->point = get_point(hit->ray.origin, hit->ray.direction, hit->distance);
	hit->normal = vec_unit(vec_sub(hit->point, sphere->origin));
	if (inside)
		hit->normal = vec_mult_scalar(hit->normal, -1);
	return (true);
}

int	sphere_intersect(t_object *object, t_hit *hit)
{
	t_sphere			*sphere;
	t_sphere_position	values;

	sphere = object->object;
	values.t = vec_dot(vec_sub(sphere->origin, hit->ray.origin),
			hit->ray.direction);
	values.p = get_point(hit->ray.origin, hit->ray.direction, values.t);
	values.y = vec_magintude(vec_sub(sphere->origin, values.p));
	if (values.y > sphere->radius)
		return (0);
	values.x = sqrt(pow(sphere->radius, sphere->radius) - pow(values.y,
				values.y));
	values.t1 = values.t - values.x;
	if (values.t1 > M_EPSILON && values.t1 < hit->distance)
		return (sphere_hit(object, hit, values.t1, 0));
	values.t2 = values.t + values.x;
	if (values.t2 > M_EPSILON && values.t2 < hit->distance)
		return (sphere_hit(object, hit, values.t2, true));
	return (0);
}
