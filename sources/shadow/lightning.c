/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lightning.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 03:59:33 by aqueiroz          #+#    #+#             */
/*   Updated: 2024/03/16 15:50:51 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

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

	result = vector_create(colors[RESULT].x, colors[RESULT].y,
			colors[RESULT].z);
	return (result);
}

static void	zero_diffuse_and_specular(t_vector *diffuse, t_vector *specular)
{
	*diffuse = vector_create(0, 0, 0);
	*specular = vector_create(0, 0, 0);
}

t_vector	lighting(t_material m, t_light light, t_hit *hit, int in_shadow)
{
	t_vector	eff_color;
	t_vector	lightv;
	t_vector	reflect_v;
	t_vector	colors[4];
	double		lg_d_norm;

	eff_color = vector_product(vector_mult(m.color, light.ratio), light.color);
	lightv = normalize(vector_diff(light.origin, hit->rec->point));
	colors[AMBIENT] = vector_mult(eff_color, m.ambient);
	lg_d_norm = fmax(0, vector_dot(lightv, hit->rec->normal));
	colors[DIFFUSE] = vector_mult(eff_color, m.diffuse * lg_d_norm);
	reflect_v = vector_reflect(vector_negate_self(&lightv), hit->rec->normal);
	colors[SPECULAR] = vector_mult(light.color, m.specular
			* pow(vector_dot(reflect_v, hit->ray->direction), m.shininess));
	if (!(vector_dot(reflect_v, hit->ray->direction) > 0))
		colors[SPECULAR] = vector_create(0, 0, 0);
	if (!(lg_d_norm >= 0 && !in_shadow))
		zero_diffuse_and_specular(&colors[DIFFUSE], &colors[SPECULAR]);
	colors[RESULT] = vector_sum(vector_sum(colors[DIFFUSE], colors[SPECULAR]),
			colors[AMBIENT]);
	normalize_result(colors);
	return (copy_and_deinit(colors));
}
