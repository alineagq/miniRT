/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_objects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 22:44:07 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/11/08 12:04:57 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	render_sphere(t_object *object)
{
	t_sphere	*sphere;
	t_data		*data;
	double		a;
	double		half_b;
	double		c;
	double		discriminant;
	double		root;
	double		t;
	t_vector3	oc;
	sphere = object->object;
	data = get_data();
	ray = data->ray;
	oc = vec3_sub(ray.origin, sphere->center);
	a = vec3_length_squared(ray.direction);
	half_b = vec3_dot(oc, ray.direction);
	c = vec3_length_squared(oc) - sphere->radius * sphere->radius;
	discriminant = half_b * half_b - a * c;
	if (discriminant < 0)
		return ;
	root = sqrt(discriminant);
	t = (-half_b - root) / a;
	if (t < 0)
		t = (-half_b + root) / a;
	p = ray_at(ray, t);
	normal = vec3_div(vec3_sub(p, sphere->center), sphere->radius);
	normal = vec3_div(normal, 2);
	normal = vec3_add(normal, vec3_new(0.5, 0.5, 0.5));
	data->image.data[(int)ray.x + (int)ray.y
		* data->image.width] = color_new(normal.x, normal.y, normal.z);
}
