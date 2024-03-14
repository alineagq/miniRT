/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_at.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 13:37:59 by aqueiroz          #+#    #+#             */
/*   Updated: 2024/03/13 20:10:51 by aqueiroz         ###   ########.fr       */
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
	comps.over_point = add_vector(comps.point, mul_scalar(comps.normalv,
				M_EPSILON));
	return (comps);
}

static int	set_record(double *closest, t_hit_record *tr,
	t_hit_record *rec, int index)
{
	*closest = tr->t;
	*rec = *tr;
	rec->index = index;
	return (1);
}

int	hit_world(t_hit hit)
{
	t_hit_record	tr;
	int				hit_any;
	t_variation		t_var;
	double			closest;
	t_object		*obj;

	hit_any = 0;
	closest = hit.t.max;;
	obj = get_data()->objects;
	while(obj)
	{
		t_var.min = hit.t.min;
		t_var.max = closest;
		if (obj->id == SPHERE && hit_sphere(*(t_sphere *)obj->object, hit.ray, t_var, &tr))
			hit_any = set_record(&closest, &tr, hit.rec, obj->index);
		else if (obj->id == PLANE)
			hit_any = hit_plane(obj, hit, &t_var, &tr);
		else if (obj->id == CYLINDER)
			hit_any = hit_cylinder(obj, hit, &t_var, &tr);
		obj = obj->next;
	}
	return (hit_any);
}

static int	init_shadow_variables(double *closest, t_variation t)
{
	*closest = t.max;
	return (0);
}

static void	set_t_var(t_variation *t_var, t_variation t, double closest)
{
	t_var->min = t.min;
	t_var->max = closest;
}

int	hittable_shadow_hit(
			t_variation t, t_hit *h, int ignore_index)
{
	t_hit_record	tr;
	t_object	*c;
	int				hit_any;
	double			close;
	t_variation		tv;

	hit_any = init_shadow_variables(&close, t);
	c = get_data()->objects;
	while (c)
	{
		if (c->index != ignore_index)
		{
			set_t_var(&tv, t, close);
			if (c->id == SPHERE && hit_sphere(*(t_sphere *)(c->object), h->ray, tv, &tr))
					hit_any = set_record(&close, &tr, h->rec, c->index);
			else if (c->id == PLANE && hit_plane(*(c->p), h->ray, tv, &tr))
					hit_any = set_record(&close, &tr, h->rec, c->index);
			else if (c->id == CYLINDER && hit_cylinder(c->y, h->ray, tv, &tr))
					hit_any = set_record(&close, &tr, h->rec, c->index);
		}
		c = c->next;
	}
	return (hit_any);
}

static int	has_shadow(t_vector point, t_light light, int ignored_index)
{
	t_vector		shadow_vector;
	t_ray			shadow_ray;
	t_hit_record	temp_record;
	t_variation		var;
	t_hit			hit;

	var.min = 0;
	var.max = INFINITY;
	shadow_vector = sub_vector(light.origin, point);
	shadow_ray.origin = add_vector(point,
			mul_scalar(unit_vector(shadow_vector), 1e-4));
	shadow_ray.direction = normalize(shadow_vector);
	temp_record.ignore_index = ignored_index;
	hit.rec = &temp_record;
	hit.ray = &shadow_ray;
	if (hittable_shadow_hit(var,
			&hit, ignored_index))
	{
		if (temp_record.t < length(&shadow_vector))
			return (1);
	}
	return (0);
}

t_vector	ray_color(t_ray ray)
{
	t_hit	hit;
	int		shadow;

	hit.t.min = 0;
	hit.t.max = INFINITY;
	hit.ray = &ray;
	hit.rec = &(t_hit_record){0};
	if (hit_world(hit))
	{
		shadow = has_shadow(hit.rec->point, get_data()->light, hit.rec->index);
		vector_negate_self(&hit.ray->direction);
		return (lighting(get_material(hit.rec->index), get_data()->light, &hit,
				shadow));
	}
	return (create_vector(0, 0, 0));
}
