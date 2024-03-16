/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_at.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 03:25:31 by aqueiroz          #+#    #+#             */
/*   Updated: 2024/03/16 03:25:56 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_vector	ray_at(t_ray ray, double t)
{
	t_vector	point3;

	point3 = vector_sum(ray.origin, vector_mult(ray.direction, t));
	return (point3);
}
