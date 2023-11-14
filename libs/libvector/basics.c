/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:07:49 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/11/14 15:11:02 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvector.h"

t_vector	add(const t_vector *u, const t_vector *v)
{
	t_vector	result;

	result.x = u->x + v->x;
	result.y = u->y + v->y;
	result.z = u->z + v->z;
	return (create_vector(result.x, result.y, result.z));
}

t_vector	sub(const t_vector *u, const t_vector *v)
{
	t_vector	result;

	result.x = u->x - v->x;
	result.y = u->y - v->y;
	result.z = u->z - v->z;
	return (create_vector(result.x, result.y, result.z));
}

t_vector	mul(const t_vector *u, const t_vector *v)
{
	t_vector	result;

	result.x = u->x * v->x;
	result.y = u->y * v->y;
	result.z = u->z * v->z;
	return (create_vector(result.x, result.y, result.z));
}

t_vector	div(const t_vector *u, const t_vector *v)
{
	t_vector	result;

	result.x = u->x / v->x;
	result.y = u->y / v->y;
	result.z = u->z / v->z;
	return (create_vector(result.x, result.y, result.z));
}
