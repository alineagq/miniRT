/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:00:58 by fsuomins          #+#    #+#             */
/*   Updated: 2023/11/14 11:05:45 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_vector	ray_at(t_ray *ray, double t)
{
	return (vec_add(ray->origin, vec_mult_scalar(ray->direction, t)));
}

int	hit_sphere(t_sphere *sphere, t_ray *ray, t_hit *rec)
{
	t_vector	oc;
	double		a;
	double		b;
	double		c;
	double		discriminant;

	oc = vec_sub(ray->origin, sphere->origin);
	a = vec_dot(ray->direction, ray->direction);
	b = 2.0 * vec_dot(oc, ray->direction);
	c = vec_dot(oc, oc) - sphere->radius * sphere->radius;
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return (0);
	rec->distance = (-b - sqrt(discriminant)) / (2.0 * a);
	rec->point = ray_at(ray, rec->distance);
	rec->normal = vec_mult_scalar(vec_sub(rec->point, sphere->origin), 1.0
			/ sphere->radius);
	return (1);
}

int	hit_object(t_object *object, t_ray *ray, t_hit *rec)
{
	if (object->id == SPHERE)
		return (hit_sphere(object->object, ray, rec));
	return (0);
}

int	hit(t_object *objects, t_ray *ray, t_hit *rec)
{
	t_hit		temp_rec;
	t_object	*temp;
	int			hit_anything;
	double		closest_so_far;

	hit_anything = 0;
	closest_so_far = ray->max;
	temp = objects;
	while (temp)
	{
		if (hit_object(temp->object, ray, &temp_rec))
		{
			{
			if (temp_rec.distance < closest_so_far)
				hit_anything = 1;
				closest_so_far = temp_rec.distance;
				*rec = temp_rec;
			}
		}
		temp = temp->next;
	}
	return (hit_anything);
}
