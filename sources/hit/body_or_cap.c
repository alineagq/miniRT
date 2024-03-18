/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   body_or_cap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 03:43:31 by aqueiroz          #+#    #+#             */
/*   Updated: 2024/03/16 03:45:54 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

double	calculate_t_bt(t_vector aot, t_ray ray, t_vector axis)
{
	if (fabs(vector_dot(ray.direction, axis)) < 1e-6)
		return (-1);
	return (vector_dot(aot, axis) / vector_dot(ray.direction, axis));
}

int	hit_caps_helper(t_hit *hit, double t_val,
	t_vector point, int is_bottom)
{
	const double	epsilon = 1e-6;
	double			radius;
	t_vector		cap;

	if (is_bottom)
		cap = hit->cyl->cap_bottom;
	else
		cap = hit->cyl->cap_top;
	radius = vector_length(vector_diff(point, cap));
	if (t_val >= hit->t.min && t_val <= hit->t.max
		&& radius <= hit->cyl->radius - epsilon)
	{
		hit->rec->t = t_val;
		hit->rec->point = point;
		if (is_bottom)
			hit->rec->normal = vector_mult(hit->cyl->axis, -1);
		else
			hit->rec->normal = hit->cyl->axis;
		set_face_normal(hit->rec, hit->ray, &hit->rec->normal);
		return (1);
	}
	return (0);
}

int	find_hit_result(t_hit hit, double t_bt[2], t_vector point_bt[2])
{
	int	hit_bt[2];

	hit_bt[0] = hit_caps_helper(&hit, t_bt[0], point_bt[0], 1);
	hit_bt[1] = hit_caps_helper(&hit, t_bt[1], point_bt[1], 0);
	if (hit_bt[0] && hit_bt[1])
	{
		if (t_bt[0] < t_bt[1])
			return (hit_caps_helper(&hit, t_bt[0], point_bt[0], 1));
		else
			return (hit_caps_helper(&hit, t_bt[1], point_bt[1], 0));
	}
	else if (hit_bt[0])
		return (hit_caps_helper(&hit, t_bt[0], point_bt[0], 1));
	else if (hit_bt[1])
		return (hit_caps_helper(&hit, t_bt[1], point_bt[1], 0));
	return (0);
}

int	hit_caps(t_cylinder c, t_ray *ray, t_variation t, t_hit_record *rec)
{
	t_hit		hit;
	double		t_bt[2];
	t_vector	point_bt[2];
	t_vector	aot_bt[2];

	hit.cyl = &c;
	hit.ray = ray;
	hit.t = t;
	hit.rec = rec;
	aot_bt[0] = vector_diff(c.cap_bottom, ray->origin);
	aot_bt[1] = vector_diff(c.cap_top, ray->origin);
	t_bt[0] = calculate_t_bt(aot_bt[0], *ray, c.axis);
	t_bt[1] = calculate_t_bt(aot_bt[1], *ray, c.axis);
	point_bt[0] = ray_at(*ray, t_bt[0]);
	point_bt[1] = ray_at(*ray, t_bt[1]);
	return (find_hit_result(hit, t_bt, point_bt));
}


int	body_or_cap(t_hit *hit, int body_hit)
{
	t_hit_record	cap_rec;
	int				cap_hit;

	cap_hit = hit_caps(*hit->cyl, hit->ray, hit->t, &cap_rec);
	if (cap_hit && body_hit)
	{
		if (cap_rec.t < hit->rec->t)
		{
			*hit->rec = cap_rec;
		}
	}
	else if (cap_hit)
	{
		*hit->rec = cap_rec;
	}
	else if (!body_hit)
		return (0);
	return (1);
}