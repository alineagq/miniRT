/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_hit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 03:49:05 by aqueiroz          #+#    #+#             */
/*   Updated: 2024/03/16 03:49:10 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static int	is_valid_intersection(double h, double rt, t_hit *hit)
{
	return (h >= 0 && h <= hit->cyl->height
		&& rt >= hit->t.min && rt <= hit->t.max);
}

static void	set_hit_record(t_hit *hit, double rt, t_vector point)
{
	hit->rec->t = rt;
	hit->rec->point = point;
}


static void	calculate_points_heights(double rt[2],
	t_hit *hit, t_vector p[2], double h[2])
{
	p[0] = ray_at(*hit->ray, rt[0]);
	h[0] = vector_dot(hit->cyl->axis, vector_diff(p[0], hit->cyl->cap_bottom));
	p[1] = ray_at(*hit->ray, rt[1]);
	h[1] = vector_dot(hit->cyl->axis, vector_diff(p[1], hit->cyl->cap_bottom));
}

int	select_hit(double rt[2], t_hit *hit, int vld_inter1, int vld_inter2)
{
	t_vector	p[2];
	double		h[2];

	calculate_points_heights(rt, hit, p, h);
	vld_inter1 = is_valid_intersection(h[0], rt[0], hit);
	vld_inter2 = is_valid_intersection(h[1], rt[1], hit);
	if (vld_inter1 && vld_inter2)
	{
		if (rt[0] < rt[1])
			set_hit_record(hit, rt[0], p[0]);
		else
			set_hit_record(hit, rt[1], p[1]);
		return (1);
	}
	else if (vld_inter1)
	{
		set_hit_record(hit, rt[0], p[0]);
		return (1);
	}
	else if (vld_inter2)
	{
		set_hit_record(hit, rt[1], p[1]);
		return (1);
	}
	return (0);
}