/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:07:49 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/11/27 10:24:16 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvector.h"

int	vector_is_equal(const t_vector u, const t_vector v)
{
	if (u.x == v.x && u.y == v.y && u.z == v.z)
		return (1);
	return (0);
}

t_vector	add_vector(const t_vector u, const t_vector v)
{
	t_vector	result;

	result.x = u.x + v.x;
	result.y = u.y + v.y;
	result.z = u.z + v.z;
	return (create_vector(result.x, result.y, result.z));
}

t_vector	sub_vector(const t_vector u, const t_vector v)
{
	t_vector	result;

	result.x = u.x - v.x;
	result.y = u.y - v.y;
	result.z = u.z - v.z;
	return (create_vector(result.x, result.y, result.z));
}

t_vector	mul_vector(const t_vector u, const t_vector v)
{
	t_vector	result;

	result.x = u.x * v.x;
	result.y = u.y * v.y;
	result.z = u.z * v.z;
	return (create_vector(result.x, result.y, result.z));
}

t_vector	div_vector(const t_vector u, const t_vector v)
{
	t_vector	result;

	result.x = u.x / v.x;
	result.y = u.y / v.y;
	result.z = u.z / v.z;
	return (create_vector(result.x, result.y, result.z));
}
