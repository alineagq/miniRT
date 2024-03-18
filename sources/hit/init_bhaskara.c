/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bhaskara.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 03:39:32 by aqueiroz          #+#    #+#             */
/*   Updated: 2024/03/16 03:39:37 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_bhaskara	init_bhaskara(t_vector pj_ori_center,
	t_vector v, double radius)
{
	t_bhaskara	bhaskara;

	bhaskara.a = vector_length_sqd(v);
	bhaskara.b = 2 * vector_dot(pj_ori_center, v);
	bhaskara.c = vector_length_sqd(pj_ori_center) - radius * radius;
	bhaskara.discr = bhaskara.b * bhaskara.b - 4 * bhaskara.a * bhaskara.c;
	return (bhaskara);
}