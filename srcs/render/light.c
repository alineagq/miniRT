/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:56:37 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/11/21 00:05:18 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static double	compute_light_dot_normal(t_light l, t_comps comps)
{
	t_vector	lightv;
	double		light_dot_normal;

	lightv = unit_vector(sub_vector(l.origin, comps.over_point));
	light_dot_normal = dot(lightv, comps.normalv);
	return (light_dot_normal);
}

static t_vector	compute_diffuse(t_light l, double light_dot_nrml, t_comps comps)
{
	t_vector	diffuse;
	t_vector	effective_color;
	t_material	material;

	material = get_material(comps.object);
	effective_color = mul_scalar(get_color(comps.object), l.ratio);
	diffuse = mul_scalar(effective_color, material.diffuse * light_dot_nrml);
	return (diffuse);
}

static t_vector	compute_ambient(t_light l, t_comps comps)
{
	t_vector	ambient;
	t_vector	effective_color;
	t_material	material;

	material = get_material(comps.object);
	effective_color = mul_scalar(get_color(comps.object), l.ratio);
	ambient = mul_scalar(effective_color, material.ambient);
	return (ambient);
}

static t_vector	compute_color(t_vector color_diffuse, t_vector color_ambient,
		t_comps comps, t_ambient amb)
{
	t_vector	color;
	t_vector	amb_color;

	amb_color = mul_scalar(amb.color, amb.ratio);
	color = add_vector(color_ambient, color_diffuse);
	color = add_vector(color, mul_vector(get_color(comps.object), amb_color));
	return (color);
}

t_vector	lighting(t_light light, t_comps comps, t_ambient amb, int shadow)
{
	t_vector	color_diffuse;
	t_vector	color_ambient;
	double		light_dot_normal;

	color_diffuse = (t_vector){0, 0, 0};
	color_ambient = compute_ambient(light, comps);
	if (shadow)
		return (compute_color(color_ambient, color_diffuse, comps, amb));
	light_dot_normal = compute_light_dot_normal(light, comps);
	if (light_dot_normal >= 0)
		color_diffuse = compute_diffuse(light, light_dot_normal, comps);
	return (compute_color(color_ambient, color_diffuse, comps, amb));
}
