/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:53:38 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/11/22 12:49:17 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvector.h"

t_vector	create_vector(double x, double y, double z)
{
	t_vector	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_vector	negate_vector(t_vector v)
{
	return (create_vector(-v.x, -v.y, -v.z));
}

void	add_eq(t_vector *v, const t_vector *u)
{
	v->x += u->x;
	v->y += u->y;
	v->z += u->z;
}

void	mul_eq(t_vector *v, double t)
{
	v->x *= t;
	v->y *= t;
	v->z *= t;
}

void	div_eq(t_vector *v, double t)
{
	mul_eq(v, 1 / t);
}
