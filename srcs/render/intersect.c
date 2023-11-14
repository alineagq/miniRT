/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 00:12:26 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/11/13 22:19:34 by fsuomins         ###   ########.fr       */
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

int	sphere_intersect(void *catch, t_hit *rec)
{
	t_sphere			*sphere;
	t_sphere_position	vars;
	
	sphere = catch;
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

int	aabb_test(t_ray ray, t_aabb box, int *aabb_hit)
{
	if (box.active == 0)
		return (1);
	if (aabb_intersect(ray, box))
	{
		if (aabb_hit)
			*aabb_hit = 1;
		return (1);
	}
	return (0);
}

int	plane_intersect(void *obj, t_hit *hit)
{
	t_plane			*plane;
	t_plane_postion	values;

	plane = obj;
	values.pl = vec_dot(plane->direction, hit->ray.direction);
	if (fabs(values.pl) < M_EPSILON)
		return (0);
	printf("pl: %f\n", values.pl);
	values.p = vec_sub(plane->origin, hit->ray.origin);
	printf("p: %f %f %f\n", values.p.x, values.p.y, values.p.z);
	printf("plane->direction: %f %f %f\n", plane->direction.x, plane->direction.y, plane->direction.z);
	values.t = vec_dot(values.p, plane->direction) / values.pl;
	printf("t: %f\n", values.t);
	if (values.t < M_EPSILON || values.t > hit->distance)
		return (0);
	hit->normal = plane->direction;
	if (values.pl > 0)
		hit->normal = vec_mult_scalar(hit->normal, -1);
	hit->point = get_point(hit->ray.origin, hit->ray.direction, values.t);
	hit->obj = obj;
	hit->distance = values.t;
	return (1);
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
		if (aabb_test(hit->ray, current->volume, &hit->aabb_hit))
		{
			if (current->id == SPHERE)
				sphere_intersect(current->object, hit);
			if (current->id == PLANE)
				plane_intersect(current->object, hit);
			// if (current->id == CYLINDER)
			// 	cylinder_intersect(current->object, hit);
		}
		current = current->next;
	}
	if (hit->obj)
		return (1);
	return (0);
}
