/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   properties.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 23:37:20 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/11/10 00:34:19 by aqueiroz         ###   ########.fr       */
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
