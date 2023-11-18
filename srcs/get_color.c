/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_vector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 19:45:08 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/11/18 19:47:07 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_intersect	*hit(t_intersect *intersections)
{
	while (intersections)
	{
		if (intersections->t >= 0)
			return (intersections);
		intersections = intersections->next;
	}
	return (NULL);
}

static void	hit_sp(t_ray ray, t_object *obj, t_intersect **inters)
{
	t_ray			tmp_ray;
	t_inter_point	inter_p;

	tmp_ray = transform_ray(ray, (t_sphere *)obj->object);
	inter_p = intersect_sphere(tmp_ray, (t_sphere *)obj->object);
	if (inter_p.hit_times != 0)
	{
		intersect_add_back(inters, new_intersect(inter_p.hit[0], obj));
		intersect_add_back(inters, new_intersect(inter_p.hit[1], obj));
	}
}

static void	hit_cy(t_ray ray, t_object *obj, t_intersect **inters)
{
	t_ray			tmp_ray;
	t_inter_point	inter_p;

	tmp_ray = transform_ray(ray, obj->cy->inv_transform);
	inter_p = intersect_cylinder(tmp_ray, obj->cy);
	if (inter_p.hit_times != 0)
	{
		intersect_add_back(inters, new_intersect(inter_p.hit[0], obj));
		intersect_add_back(inters, new_intersect(inter_p.hit[1], obj));
	}
}

static void	hit_pl(t_ray ray, t_object *obj, t_intersect **inters)
{
	t_ray			tmp_ray;
	t_inter_point	inter_p;

	tmp_ray = transform_ray(ray, obj->pl->inv_transform);
	inter_p = intersect_plane(tmp_ray);
	if (inter_p.hit_times != 0)
		intersect_add_back(inters, new_intersect(inter_p.hit[0], obj));
}

t_intersect	*intersection_calculate(t_ray ray, t_object *objects)
{
	t_intersect	*intersect;

	intersect = NULL;
	while (objects)
	{
		if (objects->type == 1)
			hit_sp(ray, objects, &intersect);
		else if (objects->type == 2)
			hit_cy(ray, objects, &intersect);
		else
			hit_pl(ray, objects, &intersect);
		objects = objects->next;
	}
	sort_lst(&intersect);
	return (intersect);
}

static t_comps	prepare_computations(t_intersect *intersects, t_ray ray)
{
	t_comps		comps;
	t_intersect	*closest_intersection;

	closest_intersection = hit(intersects);
	comps.t = closest_intersection->t;
	comps.point = position(ray, closest_intersection->t);
	comps.eyev = s_multiply(ray.direction, -1);
	comps.normalv = normal_at(closest_intersection->object, comps.point);
	comps.object = closest_intersection->object;
	if (dot(comps.normalv, comps.eyev) < 0)
	{
		comps.inside = 1;
		comps.normalv = s_multiply(comps.normalv, -1);
	}
	else
		comps.inside = 0;
	comps.over_point = add(comps.point, s_multiply(comps.normalv, M_EPSILON));
	return (comps);
}

t_vector	color_at(t_ray ray)
{
	t_vector	color;
	t_comps		comps;
	t_intersect	*intersects;

	intersects = intersection_calculate(ray, get_data()->objects);
	if (intersects == NULL || hit(intersects) == NULL)
	{
		clear_intersect(&intersects);
		return ((t_vector){0, 0, 0});
	}
	comps = prepare_computations(intersects, ray);
	clear_intersect(&intersects);
	color = shade_hit(get_data()->camera, comps);
	return (color);
}
