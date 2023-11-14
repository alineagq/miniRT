/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:52:52 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/11/14 15:17:18 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvector.h"

t_vector	add_scalar(t_vector v, double scalar)
{
	t_vector	result;

	result.x = v.x + scalar;
	result.y = v.y + scalar;
	result.z = v.z + scalar;
	return (result);
}

t_vector	sub_scalar(t_vector v, double scalar)
{
	t_vector	result;

	result.x = v.x - scalar;
	result.y = v.y - scalar;
	result.z = v.z - scalar;
	return (result);
}

t_vector	mul_scalar(t_vector v, double scalar)
{
	t_vector	result;

	result.x = v.x * scalar;
	result.y = v.y * scalar;
	result.z = v.z * scalar;
	return (result);
}

t_vector	div_scalar(t_vector v, double scalar)
{
	t_vector	result;

	result.x = v.x / scalar;
	result.y = v.y / scalar;
	result.z = v.z / scalar;
	return (result);
}

t_vector	cross(const t_vector *u, const t_vector *v)
{
	t_vector	result;

	result.x = u->y * v->z - u->z * v->y;
	result.y = u->z * v->x - u->x * v->z;
	result.z = u->x * v->y - u->y * v->x;
	return (create_vector(result.x, result.y, result.z));
}
