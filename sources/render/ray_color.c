/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 03:13:38 by aqueiroz          #+#    #+#             */
/*   Updated: 2024/03/16 04:08:34 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static t_material	get_material(t_object *world, int index)
{
	t_material		material;

	while (world)
	{
		if (index == world->index && world->shape == PLANE)
			material = world->plane->material;
		else if (index == world->index && world->shape == SPHERE)
			material = world->sphere->material;
		else if (index == world->index && world->shape == CYLINDER)
			material = world->cyl->material;
		world = world->next;
	}
	return (material);
}

t_vector			ray_color(t_ray ray, t_object *world, t_light light)
{
	t_hit			hit;
	int				in_shadow;

	hit.t.min = 0;
	hit.t.max = HUGE_VAL;
	hit.ray = &ray;
	hit.rec = &(t_hit_record){0};
	if (hittable_list_hit(world, hit.ray, hit.t, hit.rec))
	{
		in_shadow = is_shadowed(hit.rec->point, light, world, hit.rec->index);
		vector_negate_self(&hit.ray->direction);
		return (lighting(get_material(world, hit.rec->index), light,
				&hit, in_shadow));
	}
	return (vector_create(0, 0, 0));
}
