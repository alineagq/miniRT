/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable_list_hit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 03:21:09 by aqueiroz          #+#    #+#             */
/*   Updated: 2024/03/16 17:09:19 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static int	set_record(double *closest, t_hit_record *tr,
	t_hit_record *rec, int index)
{
	*closest = tr->t;
	*rec = *tr;
	rec->index = index;
	return (1);
}


int	hittable_list_hit(t_object *list, t_ray *ray,
			t_variation t, t_hit_record *rec)
{
	t_hit_record	tr;
	int				hit_any;
	double			closest;
	t_variation		t_var;

	hit_any = 0;
	closest = t.max;
	while (list)
	{
		t_var.min = t.min;
		t_var.max = closest;
		if (list->shape == SPHERE && hit_sphere(*(list->sphere), ray, t_var, &tr))
				hit_any = set_record(&closest, &tr, rec, list->index);
		else if (list->shape == PLANE && hit_plane(*(list->plane), ray, t_var, &tr))
				hit_any = set_record(&closest, &tr, rec, list->index);
		else if (list->shape == CYLINDER && hit_cylinder(list->cyl, ray, t_var, &tr))
				hit_any = set_record(&closest, &tr, rec, list->index);
		list = list->next;
	}
	return (hit_any);
}