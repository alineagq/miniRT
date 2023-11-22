/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 13:52:20 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/11/20 14:56:49 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	hit_cylinder(t_ray ray, t_hit *obj, t_intersect **inters)
{
	t_ray			tmp_ray;
	t_inter_point	inter_p;
	t_cylinder		*cy;

	cy = (t_cylinder *)obj->object;
	tmp_ray = transform_ray(ray, cy->invert);
	inter_p = intersect_cylinder(tmp_ray, cy);
	if (inter_p.hit_times != 0)
	{
		intersect_add_back(inters, new_intersect(inter_p.hit[0], obj));
		intersect_add_back(inters, new_intersect(inter_p.hit[1], obj));
	}
}
