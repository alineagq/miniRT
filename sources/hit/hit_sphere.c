/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 03:24:00 by aqueiroz          #+#    #+#             */
/*   Updated: 2024/03/16 17:08:57 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static int	check_root_value(t_variation t, t_vector delta, double sqrt_discr,
		double *root)
{
	if (t.min > *root || *root > t.max)
	{
		*root = (-delta.y + sqrt_discr) / delta.x;
		if (t.min > *root || *root > t.max)
			return (0);
	}
	return (1);
}

static t_vector	set_out_normal(t_hit_record *rec, t_sphere sphere)
{
	t_vector	new;

	new = vector_div(vector_diff(rec->point, sphere.center), sphere.radius);
	return (new);
}

int	hit_sphere(t_sphere sphere, t_ray *ray, t_variation t, t_hit_record *rec)
{
	t_vector	distance;
	t_vector	delta;
	t_vector	out_normal;
	double		discr;
	double		root;

	distance = vector_diff(ray->origin, sphere.center);
	delta.x = vector_length_sqd(ray->direction);
	delta.y = vector_dot(distance, ray->direction);
	delta.z = vector_length_sqd(distance) - sphere.radius * sphere.radius;
	discr = delta.y * delta.y - (delta.x * delta.z);
	if (discr < 0)
		return (0);
	root = (-delta.y - sqrt(discr)) / delta.x;
	if (!check_root_value(t, delta, sqrt(discr), &root))
		return (0);
	rec->t = root;
	rec->point = ray_at(*ray, rec->t);
	out_normal = set_out_normal(rec, sphere);
	set_face_normal(rec, ray, &out_normal);
	return (1);
}
