/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_shadow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 03:52:24 by aqueiroz          #+#    #+#             */
/*   Updated: 2024/03/16 17:08:24 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static int	set_record(double *closest, t_hit_record *tr,
	t_hit_record *rec, int index)
{
	*closest = tr->t;
	*rec = *tr;
	rec->index = index;
	return (1);
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

int	hittable_shadow_hit(t_object *list,
			t_variation t, t_hit *h, int ignore_index)
{
	t_hit_record	tr;
	int				hit_any;
	double			close;
	t_variation		tv;

	hit_any = init_shadow_variables(&close, t);
	while (list)
	{
		if (list->index != ignore_index)
		{
			set_t_var(&tv, t, close);
			if (list->shape == SPHERE && hit_sphere(*(list->sphere), h->ray, tv, &tr))
					hit_any = set_record(&close, &tr, h->rec, list->index);
			else if (list->shape == PLANE && hit_plane(*(list->plane), h->ray, tv, &tr))
					hit_any = set_record(&close, &tr, h->rec, list->index);
			else if (list->shape == CYLINDER && hit_cylinder(list->cyl, h->ray, tv, &tr))
					hit_any = set_record(&close, &tr, h->rec, list->index);
		}
		list = list->next;
	}
	return (hit_any);
}

int	is_shadowed(t_vector point, t_light light,
				t_object *world, int ignored_index)
{
	t_vector		shadow_vector;
	t_ray			shadow_ray;
	t_hit_record	temp_record;
	t_variation		var;
	t_hit			hit;

	var.min = 0;
	var.max = HUGE_VAL;
	shadow_vector = vector_diff(light.origin, point);
	shadow_ray.origin = vector_sum(point,
			vector_mult(vector_unit(shadow_vector), 1e-4));
	shadow_ray.direction = normalize(shadow_vector);
	temp_record.ignore_index = ignored_index;
	hit.rec = &temp_record;
	hit.ray = &shadow_ray;
	if (hittable_shadow_hit(world, var,
			&hit, ignored_index))
	{
		if (temp_record.t < vector_length(shadow_vector))
			return (1);
	}
	return (0);
}
