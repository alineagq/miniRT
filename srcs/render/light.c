/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:56:37 by aqueiroz          #+#    #+#             */
/*   Updated: 2024/03/10 20:36:22 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"
#define AMBIENT 0
#define DIFFUSE 1
#define SPECULAR 2
#define RESULT 3

t_vector	normalize(t_vector vector)
{
	t_vector	result;
	double		len;

	len = length(&vector);
	if (len == 0)
		return (vector);
	result.x = vector.x / len;
	result.y = vector.y / len;
	result.z = vector.z / len;
	return (result);
}

static void	normalize_result(t_vector *colors)
{
	if (fabs(colors[RESULT].x) > 1)
		colors[RESULT].x = 1;
	if (fabs(colors[RESULT].y) > 1)
		colors[RESULT].y = 1;
	if (fabs(colors[RESULT].z) > 1)
		colors[RESULT].z = 1;
}

static t_vector	copy_and_deinit(t_vector *colors)
{
	t_vector	result;

	result = create_vector(colors[RESULT].x, colors[RESULT].y,
			colors[RESULT].z);
	return (result);
}

static void	zero_diffuse_and_specular(t_vector *diffuse, t_vector *specular)
{
	*diffuse = create_vector(0, 0, 0);
	*specular = create_vector(0, 0, 0);
}

t_vector	vector_reflect(t_vector v, t_vector n)
{
	t_vector		result;
	const double	dot_product = 2 * (v.x * n.x + v.y * n.y + v.z * n.z);

	result.x = v.x - dot_product * n.x;
	result.y = v.y - dot_product * n.y;
	result.z = v.z - dot_product * n.z;
	return (result);
}

t_vector	lighting(t_material m, t_light light, t_hit *hit, int in_shadow)
{
	t_vector	eff_color;
	t_vector	lightv;
	t_vector	reflect_v;
	t_vector	colors[4];
	double		lg_d_norm;

	eff_color = mul_vector(mul_scalar(m.color, light.ratio),
			light.color);
	lightv = normalize(sub_vector(light.origin, hit->rec->point));
	colors[AMBIENT] = mul_scalar(eff_color, m.ambient);
	lg_d_norm = fmax(0, dot(lightv, hit->rec->normal));
	colors[DIFFUSE] = mul_scalar(eff_color, m.diffuse * lg_d_norm);
	reflect_v = vector_reflect(vector_negate_self(&lightv), hit->rec->normal);
	colors[SPECULAR] = mul_scalar(light.color, m.specular
			* pow(dot(reflect_v, hit->ray->direction), m.shininess));
	if (!(dot(reflect_v, hit->ray->direction) > 0))
		colors[SPECULAR] = create_vector(0, 0, 0);
	if (!(lg_d_norm >= 0 && !in_shadow))
		zero_diffuse_and_specular(&colors[DIFFUSE], &colors[SPECULAR]);
	colors[RESULT] = add_vector(add_vector(colors[DIFFUSE], colors[SPECULAR]),
			colors[AMBIENT]);
	normalize_result(colors);
	return (copy_and_deinit(colors));
}
