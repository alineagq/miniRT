/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:39:08 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/11/13 22:33:36 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_vector	mat4_get(t_mat4 mx, t_mat_element type)
{
	if (type == m_right)
		return ((t_vector){mx.data[0][0], mx.data[0][1], mx.data[0][2]});
	if (type == m_up)
		return ((t_vector){mx.data[1][0], mx.data[1][1], mx.data[1][2]});
	if (type == m_forward)
		return ((t_vector){mx.data[2][0], mx.data[2][1], mx.data[2][2]});
	if (type == m_origin)
		return ((t_vector){mx.data[3][0], mx.data[3][1], mx.data[3][2]});
	return ((t_vector){0, 0, 0});
}

int	camera_ray(t_data *scene, t_ray *ray, int u, int v)
{
	t_vector	worldwide;

	worldwide.x = (2 * ((u + 0.5) / scene->mlx.image->width) - 1)
		* scene->camera.view_range * scene->ratio;
	worldwide.y = (1 - 2 * ((v + 0.5) / scene->mlx.image->height)
			* scene->camera.view_range);
	worldwide.z = 1;
	ray->origin = mat4_get(scene->camera.world, m_origin);
	ray->direction = vec_unit(mat4_mult_dir(scene->camera.world, worldwide));
	ray->max = INFINITY;
	return (1);
}

unsigned int	rgb_to_data(const t_color color)
{
	int	r;
	int	g;
	int	b;

	r = (double)(color.r);
	g = (double)(color.g);
	b = (double)(color.b * 255);
	return (r << 16 | g << 8 | b);
}

void	calculate_color(mlx_image_t **image, int u, int v, t_color color)
{
	mlx_put_pixel(*image, u, v, rgb_to_data(color));
}

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
			if (temp_rec.distance < closest_so_far)
			{
				hit_anything = 1;
				closest_so_far = temp_rec.distance;
				*rec = temp_rec;
			}
		}
		temp = temp->next;
	}
	return (hit_anything);
}

t_vector	rgb_to_vector(t_color color)
{
	return ((t_vector){(double)color.r, (double)color.g, (double)color.b});
}

t_vector	flat_shade(t_hit *hit)
{
	t_vector	color;
	double		scalar;

	color = (t_vector){0, 0, 0};
	scalar = 0.0;
	if (!vec_comp_scalar(hit->normal, 0.0))
	{
		color = (t_vector){sin(hit->normal.x * 2.5) * 0.5 + 0.5,
			sin(hit->normal.y * 2.5 + 2.0) * 0.5 + 0.5, sin(hit->normal.z * 2.5
				+ 4.0) * 0.5 + 0.5};
		scalar = vec_magintude(color) * 0.5773502692;
	}
	color = vec_mult(rgb_to_vector(hit->color), (t_vector){scalar, scalar,
			scalar});
	return (vec_clamp(color, 0.0, 1.0));
}

static int	is_shadow(t_data *scene, t_vector origin, t_vector dir)
{
	t_hit	shadow;

	ft_memset(&shadow, 0, sizeof(t_hit));
	shadow.ray.direction = vec_unit(dir);
	shadow.ray.origin = vec_add(origin, vec_mult_scalar(shadow.ray.direction,
				M_EPSILON));
	shadow.ray.max = M_INFINITY;
	shadow.distance = M_INFINITY;
	intersect(&shadow);
	if (shadow.distance > vec3_mag(dir))
		return (false);
	return (true);
}

t_vector	s_shaded(t_data *scene, t_hit *rec)
{
	t_vector	l_diffuse;
	t_light		lights;

	lights = scene->light;
	l_diffuse = vec_mult(rgb_to_vector(rec->color),
			rgb_to_vector(scene->ambient.color));
	lights->dir = vec3_sub(lights->origin, rec->point);
	if (is_shadow(scene, rec->point, lights->dir) == false)
	{
		lights->angle = clamp(vec3_dot(vec3_unit(lights->dir), rec->normal), 0,
				1);
		l_diffuse = vec3_add(l_diffuse, vec3_mult_s(lights->color,
					lights->angle));
	}
	return (vec3_clamp(vec3_mult(rec->color, l_diffuse), 0.0, 1.0));
}

t_vector	shade(t_hit *hit)
{
	t_vector	color;

	color = (t_vector){0, 0, 0};
	if (get_data()->viewport == flat)
		color = flat_shade(hit);
	if (get_data()->viewport == aabb)
		color = s_aabb(hit);
	if (get_data()->viewport == shaded)
		color = shaded_shade(hit);
	return (color);
}

t_color	vector_to_rgb(t_vector color)
{
	return ((t_color){(int)(color.x), (int)(color.y), (int)(color.z)});
}

t_vector	s_aabb(t_hit *rec)
{
	if (rec->aabb_hit)
		return ((t_vector){0.75, 0.0, 0.0});
	return ((t_vector){0.5, 0.5, 0.5});
}

t_color	ray_color(t_ray *ray)
{
	t_hit		*rec;
	t_vector	target;

	rec = ft_calloc(sizeof(t_hit), 1);
	rec->ray = *ray;
	rec->distance = INFINITY;
	rec->ray.max = INFINITY;
	target = (t_vector){0, 0, 0};
	if (intersect(rec))
	{
		printf("hit\n");
		rec->color = rec->obj->diffuse;
		target = shade(rec);
		printf("target: %f %f %f\n", target.x, target.y, target.z);
		rec->obj = NULL;
		free(rec);
		return (vector_to_rgb(target));
	}
	else if (get_data()->viewport == aabb && rec->aabb_hit)
	{
		target = s_aabb(rec);
		rec->obj = NULL;
		free(rec);
		return (vector_to_rgb(target));
	}
	rec->obj = NULL;
	free(rec);
	return (vector_to_rgb(target));
}

void	write_color(mlx_image_t **image, int u, int v, t_color color)
{
	calculate_color(image, u, v, color);
}

int	render(void)
{
	t_data	*scene;
	t_color	color;
	t_ray	ray;

	scene = get_data();
	scene->u = 0;
	scene->v = 0;
	while (scene->u < (int)scene->mlx.image->width)
	{
		while (scene->v < (int)scene->mlx.image->height)
		{
			camera_ray(scene, &ray, scene->u, scene->v);
			color = ray_color(&ray);
			if (color.r || color.g || color.b)
				printf("color: %d %d %d\n", color.r, color.g, color.b);
			write_color(&scene->mlx.image, scene->u, scene->v, color);
			scene->v++;
		}
		scene->u++;
	}
	return (1);
}
