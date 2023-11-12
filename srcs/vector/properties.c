/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   properties.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 23:37:20 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/11/11 21:51:28 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_vector	vec_unit(t_vector v)
{
	double	magnitude;

	magnitude = vec_magintude(v);
	return (vec_div_scalar(v, magnitude));
}

double	vec_magintude(t_vector v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

t_vector	vec_div(t_vector v1, t_vector v2)
{
	return ((t_vector){v1.x / v2.x, v1.y / v2.y, v1.z / v2.z});
}

t_vector	get_point(t_vector ro, t_vector rd, double t)
{
	return (vec_add(ro, vec_mult_scalar(rd, t)));
}

int	vec_comp_scalar(t_vector v1, double v2)
{
	if (fabs(v1.x - v2) < M_EPSILON && fabs(v1.y - v2) < M_EPSILON && fabs(v1.z
			- v2) < M_EPSILON)
		return (1);
	return (0);
}

double	clamp(double value, double min, double max)
{
	if (value < min)
		return (min);
	if (value > max)
		return (max);
	return (value);
}

t_vector	vec_clamp(t_vector v, double min, double max)
{
	return ((t_vector){clamp(v.x, min, max), clamp(v.y, min, max), clamp(v.z,
			min, max)});
}
