/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aabb.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 23:04:23 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/11/09 23:09:03 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	create_box(t_aabb *box)
{
	const t_vector	max = {M_INFINITY, M_INFINITY, M_INFINITY};
	const t_vector	min = {-M_INFINITY, -M_INFINITY, -M_INFINITY};

	box->min = min;
	box->max = max;
	box->active = 1;
	return (1);
}

t_vector	vec_min(t_vector v1, t_vector v2)
{
	return ((t_vector){fmin(v1.x, v2.x), fmin(v1.y, v2.y), fmin(v1.z, v2.z)});
}

t_vector	vec_max(t_vector v1, t_vector v2)
{
	return ((t_vector){fmax(v1.x, v2.x), fmax(v1.y, v2.y), fmax(v1.z, v2.z)});
}

int	box_add_vec(t_aabb *volume, t_vector vec)
{
	if (volume->active == 0)
		return (0);
	volume->min = vec_min(volume->min, vec);
	volume->max = vec_max(volume->max, vec);
	return (1);
}
