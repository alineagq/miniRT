/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:06:01 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/11/22 10:48:59 by aqueiroz         ###   ########.fr       */
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

void	print_t_vector(const t_vector v)
{
	static int	i;

	i = 0;
	if (i == 0)
	{
		printf("%f %f %f\n", v.x, v.y, v.z);
		i++;
	}
}

t_vector	s_division(t_vector a, double n)
{
	return (mul_scalar(a, 1 / n));
}

t_vector	unit_vector(t_vector v)
{
	return (s_division(v, length(&v)));
}

double	dot(const t_vector u, const t_vector v)
{
	return (u.x * v.x + u.y * v.y + u.z * v.z);
}
