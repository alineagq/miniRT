/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 13:52:27 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/11/22 20:04:28 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	hit_sphere(t_ray ray, t_hit *obj, t_intersect **inters)
{
	t_ray			tmp_ray;
	t_inter_point	inter_p;
	t_sphere		*sp;

	sp = (t_sphere *)obj->object;
	tmp_ray = transform_ray(ray, sp->invert);
	printf("tmp_ray.origin: %f, %f, %f\n", tmp_ray.origin.x, tmp_ray.origin.y, tmp_ray.origin.z);
	printf("tmp_ray.direction: %f, %f, %f\n", tmp_ray.direction.x, tmp_ray.direction.y, tmp_ray.direction.z);
	
	inter_p = intersect_sphere(tmp_ray, sp);
	if (inter_p.hit_times != 0)
	{
		intersect_add_back(inters, new_intersect(inter_p.hit[0], obj));
		intersect_add_back(inters, new_intersect(inter_p.hit[1], obj));
	}
}
