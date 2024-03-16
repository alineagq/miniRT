/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 03:35:56 by aqueiroz          #+#    #+#             */
/*   Updated: 2024/03/16 17:09:12 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"


int	hit_cylinder(t_cylinder *cyl, t_ray *ray, t_variation t, t_hit_record *rec)
{
	t_hit		hit;
	t_vector	v;
	t_vector	v_origin_center;
	t_vector	pj_ori_center;
	t_bhaskara	bhaskara;

	hit = init_hit(cyl, ray, t, rec);
	v_origin_center = vector_diff(ray->origin, cyl->cap_bottom);
	pj_ori_center = vector_project(v_origin_center, cyl->axis);
	v = vector_project(ray->direction, cyl->axis);
	bhaskara = init_bhaskara(pj_ori_center, v, cyl->radius);
	if (bhaskara.discr < 0)
		return (0);
	bhaskara.root[0] = (-bhaskara.b - sqrt(bhaskara.discr)) / (2 * bhaskara.a);
	bhaskara.root[1] = (-bhaskara.b + sqrt(bhaskara.discr)) / (2 * bhaskara.a);
	if (!body_or_cap(&hit, select_hit(bhaskara.root, &hit, 0, 0)))
		return (0);
	update_hit_record(rec, rec->point, cyl->cap_bottom, cyl->axis);
	set_face_normal(rec, ray, &rec->normal);
	if (!body_or_cap(&hit, select_hit(bhaskara.root, &hit, 0, 0)))
		return (0);
	return (1);
}