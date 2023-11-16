/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:06:01 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/11/14 23:36:36 by aqueiroz         ###   ########.fr       */
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
	static int	i = 0;
	if (i == 0)
	{
		printf("%f %f %f\n", v.x, v.y, v.z);
		i++;
	}
}

t_vector	unit_vector(t_vector v)
{
	return (div_scalar(v, length(&v)));
}

double	dot(const t_vector u, const t_vector v)
{
	return (u.x * v.x + u.y * v.y + u.z * v.z);
}
