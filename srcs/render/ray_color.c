/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:51:16 by fsuomins          #+#    #+#             */
/*   Updated: 2023/11/14 10:54:31 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"


t_vector	s_aabb(t_hit *rec)
{
	if (rec->aabb_hit)
		return ((t_vector){0.75, 0.0, 0.0});
	return ((t_vector){0.5, 0.5, 0.5});
}

t_color	vector_to_rgb(t_vector color)
{
	return ((t_color){(int)(color.x), (int)(color.y), (int)(color.z)});
}

t_color	ray_color(t_ray *ray)
{
	t_hit		*rec;
	t_vector	target;

	rec = ft_calloc(sizeof(t_hit), 1);
	rec->ray = *ray;
	rec->distance = INFINITY;
	rec->ray.max = INFINITY;
	target = (t_vector){0, 0, 0};
	if (intersect(rec))
	{
		printf("hit\n");
		rec->color = rec->obj->diffuse;
		target = shade(rec);
		printf("target: %f %f %f\n", target.x, target.y, target.z);
		rec->obj = NULL;
		free(rec);
		return (vector_to_rgb(target));
	}
	else if (get_data()->viewport == aabb && rec->aabb_hit)
	{
		target = s_aabb(rec);
		rec->obj = NULL;
		free(rec);
		return (vector_to_rgb(target));
	}
	rec->obj = NULL;
	free(rec);
	return (vector_to_rgb(target));
}
