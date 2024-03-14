/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 13:52:27 by aqueiroz          #+#    #+#             */
/*   Updated: 2024/03/10 21:44:35 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static int	check_root_value(t_variation t,
			t_vector delta,
			double sqrt_discr,
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

	new = div_scalar(sub_vector(rec->point, sphere.center), sphere.radius);
	return (new);
}

t_vector	ray_at(t_ray ray, double t)
{
	t_vector	v;

	v = add_vector(ray.origin, mul_scalar(ray.direction, t));
	return (v);
}

void	set_face_normal(t_hit_record *rec, t_ray *ray, t_vector *out_normal)
{
	rec->front_face = dot(ray->direction, *out_normal) < 0;
	if (rec->front_face)
		rec->normal = *out_normal;
	else
		rec->normal = vector_negate_self(out_normal);
}

int	hit_sphere(t_sphere sphere, t_ray *ray, t_variation t, t_hit_record *rec)
{
	t_vector	distance;
	t_vector	delta;
	t_vector	out_normal;
	double		discr;
	double		root;

	distance = sub_vector(ray->origin, sphere.center);
	delta.x = length_squared(&ray->direction);
	delta.y = dot(distance, ray->direction);
	delta.z = length_squared(&distance) - sphere.radius * sphere.radius;
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
