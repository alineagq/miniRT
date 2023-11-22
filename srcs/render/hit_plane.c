/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 13:52:25 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/11/20 14:55:40 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_inter_point	intersect_plane(t_ray ray)
{
	t_inter_point	intersect;

	intersect.hit_times = 0;
	if (fabs(ray.direction.y) < M_EPSILON)
		return (intersect);
	intersect.hit_times = 1;
	intersect.hit[0] = -ray.origin.y / ray.direction.y;
	return (intersect);
}

void	hit_plane(t_ray ray, t_hit *obj, t_intersect **inters)
{
	t_ray			tmp_ray;
	t_inter_point	inter_p;
	t_plane			*pl;

	pl = (t_plane *)obj->object;
	tmp_ray = transform_ray(ray, pl->invert);
	inter_p = intersect_plane(tmp_ray);
	if (inter_p.hit_times != 0)
		intersect_add_back(inters, new_intersect(inter_p.hit[0], obj));
}
