/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 21:23:55 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/11/15 00:54:09 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_ray	create_ray(const t_vector origin, const t_vector direction)
{
	t_ray	r;

	r.origin = origin;
	r.direction = direction;
	return (r);
}

t_vector	ray_at(const t_ray *r, double t)
{
	t_vector	scaled_dir;

	scaled_dir = mul_scalar(r->direction, t);
	return (add_vector(r->origin, scaled_dir));
}

int	hit_sphere(const t_vector center, double radius, const t_ray r)
{
	t_vector	oc;
	double		a;
	double		b;
	double		c;
	double		discriminant;

	oc = sub_vector(r.origin, center);
	print_t_vector(oc);
	a = dot(r.direction, r.direction);
	b = 2.0 * dot(oc, r.direction);
	c = dot(oc, oc) - radius * radius;
	discriminant = b * b - 4 * a * c;
	return (discriminant >= 0);
}

t_vector	ray_color(const t_ray r)
{
	t_vector	unit_direction;
	double		t;
	t_vector	color;

	unit_direction = unit_vector(r.direction);
	t = 0.5 * (unit_direction.y + 1.0);
	color = add_vector(mul_scalar(create_vector(1.0, 1.0, 1.0), (1.0 - t)),
			mul_scalar(create_vector(0.5, 0.7, 1.0), t));
	return (color);
}
