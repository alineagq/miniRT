/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:06:01 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/11/14 15:12:59 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvector.h"

double	length(const t_vector *v)
{
	return (sqrt(v->x * v->x + v->y * v->y + v->z * v->z));
}

double	length_squared(const t_vector *v)
{
	return (v->x * v->x + v->y * v->y + v->z * v->z);
}

void	print_t_vector(const t_vector *v)
{
	printf("%f %f %f", v->x, v->y, v->z);
}

t_vector	unit_vector(t_vector v)
{
	return (div_double(&v, length(&v)));
}

double	dot(const t_vector *u, const t_vector *v)
{
	return (u->x * v->x + u->y * v->y + u->z * v->z);
}
