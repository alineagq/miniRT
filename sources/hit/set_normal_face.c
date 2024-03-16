/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_normal_face.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 03:27:12 by aqueiroz          #+#    #+#             */
/*   Updated: 2024/03/16 03:27:22 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	set_face_normal(t_hit_record *rec, t_ray *ray, t_vector *out_normal)
{
	rec->front_face = vector_dot(ray->direction, *out_normal) < 0;
	if (rec->front_face)
		rec->normal = *out_normal;
	else
		rec->normal = vector_negate_self(out_normal);
}
