/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:42:54 by fsuomins          #+#    #+#             */
/*   Updated: 2023/11/09 23:00:25 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_vector	vec_sub_scalar(t_vector vec, double scalar)
{
	t_vector	result;

	result.x = vec.x - scalar;
	result.y = vec.y - scalar;
	result.z = vec.z - scalar;
	return (result);
}

t_vector	vec_add_scalar(t_vector vec, double scalar)
{
	t_vector	result;

	result.x = vec.x + scalar;
	result.y = vec.y + scalar;
	result.z = vec.z + scalar;
	return (result);
}

t_vector	vec_mult_scalar(t_vector vec, double scalar)
{
	t_vector	result;

	result.x = vec.x * scalar;
	result.y = vec.y * scalar;
	result.z = vec.z * scalar;
	return (result);
}

t_vector	vec_div_scalar(t_vector vec, double scalar)
{
	t_vector	result;

	result.x = vec.x / scalar;
	result.y = vec.y / scalar;
	result.z = vec.z / scalar;
	return (result);
}

double	vec_dot(t_vector v1, t_vector v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}
