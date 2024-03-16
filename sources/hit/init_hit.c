/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 03:38:43 by aqueiroz          #+#    #+#             */
/*   Updated: 2024/03/16 03:38:57 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_hit	init_hit(t_cylinder *cyl, t_ray *ray, t_variation t,
	t_hit_record *rec)
{
	t_hit	hit;

	hit.cyl = cyl;
	hit.ray = ray;
	hit.t = t;
	hit.rec = rec;
	return (hit);
}