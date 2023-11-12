/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aabb_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 00:17:15 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/11/11 20:25:50 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

double	setcnd(int condition, double pos, double neg)
{
	if (condition)
		return (pos);
	return (neg);
}


static t_vector	get_minmax(const t_aabb volume, const int sign)
{
	if (sign)
		return (volume.max);
	return (volume.min);
}

int	aabb_intersect(const t_ray ray, t_aabb volume)
{
	t_vector	inverse;
	t_vector	sign;
	t_aabb		test;

	inverse = vec_div((t_vector){1.0, 1.0, 1.0}, ray.direction);
	sign = (t_vector){inverse.x < 0, inverse.y < 0, inverse.z < 0};
	test.min.x = (get_minmax(volume, 0 - sign.x).x - ray.origin.x) * inverse.x;
	test.max.x = (get_minmax(volume, 1 - sign.x).x - ray.origin.x) * inverse.x;
	test.min.y = (get_minmax(volume, 0 - sign.y).y - ray.origin.y) * inverse.y;
	test.max.y = (get_minmax(volume, 1 - sign.y).y - ray.origin.y) * inverse.y;
	if (test.min.x > test.max.y || test.min.y > test.max.x)
		return (0);
	test.min.x = setcnd(test.min.y > test.min.x, test.min.y, test.min.x);
	test.min.x = setcnd(test.min.y > test.min.x, test.min.y, test.min.x);
	test.max.x = setcnd(test.max.y < test.max.x, test.max.y, test.max.x);
	test.min.z = (get_minmax(volume, 0 - sign.z).z - ray.origin.z) * inverse.z;
	test.max.z = (get_minmax(volume, 1 - sign.z).z - ray.origin.z) * inverse.z;
	if (test.min.x > test.max.z || test.min.z > test.max.x)
		return (0);
	test.min.x = setcnd(test.min.z > test.min.x, test.min.z, test.min.x);
	test.max.x = setcnd(test.max.z < test.max.x, test.max.z, test.max.x);
	if (test.min.x >= 0.0 || test.max.x >= 0.0)
		return (1);
	return (0);
}

int	aabb_test(const t_ray ray, const t_aabb volume, int *hit)
{
	// if (volume.active == 0)
	// 	return (1);
	printf("%d\n", volume.active);
	printf("%f\n", ray.direction.x);
	printf("%d\n", *hit);
	// if (aabb_intersect(ray, volume))
	// {
	// 	if (hit)
	// 		*hit = 1;
	// 	return (1);
	// }
	return (0);
}
