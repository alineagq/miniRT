/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 00:12:26 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/11/11 20:42:09 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static int	sphere_hit(t_object *catch, t_hit *rec, double t, int inside)
{
	t_sphere	*sphere;

	sphere = catch->object;
	rec->obj = catch;
	rec->distance = t;
	rec->point = get_point(rec->ray.origin, rec->ray.direction, rec->distance);
	rec->normal = vec_unit(vec_sub(rec->point, sphere->origin));
	if (inside)
		rec->normal = vec_mult_scalar(rec->normal, -1);
	return (1);
}

int	sphere_intersect(t_object *catch, t_hit *rec)
{
	t_sphere			*sphere;
	t_sphere_position	vars;

	sphere = catch->object;
	vars.t = vec_dot(vec_sub(sphere->origin, rec->ray.origin),
			rec->ray.direction);
	vars.p = get_point(rec->ray.origin, rec->ray.direction, vars.t);
	vars.y = vec_magintude(vec_sub(sphere->origin, vars.p));
	if (vars.y > sphere->radius)
		return (0);
	vars.x = sqrt(pow(sphere->radius, sphere->radius) - pow(vars.y, vars.y));
	vars.t1 = vars.t - vars.x;
	if (vars.t1 > M_EPSILON && vars.t1 < rec->distance)
		return (sphere_hit(catch, rec, vars.t1, 0));
	vars.t2 = vars.t + vars.x;
	if (vars.t2 > M_EPSILON && vars.t2 < rec->distance)
		return (sphere_hit(catch, rec, vars.t2, 1));
	return (0);
}

int	intersect(t_hit *hit)
{
	t_object	*current;

	current = get_data()->objects;
	if (hit->ray.max == 0)
		return (0);
	hit->aabb_hit = 0;
	while (current)
	{
		if (aabb_intersect(hit->ray, current->volume) && current->volume.active)
		{
			if (hit)
				hit->aabb_hit = 1;
			if (current->id == SPHERE)
				sphere_intersect(current->object, hit);
		}
		current = current->next;
	}
	return (1);
}
