/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_material.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 00:35:28 by aqueiroz          #+#    #+#             */
/*   Updated: 2024/03/16 00:35:46 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_material	default_material(t_vector color)
{
	t_material	m;

	m.ambient = get_data()->ambient.ratio;
	m.diffuse = 0.9;
	m.specular = 0;
	m.shininess = 200;
	m.color = vector_create(color.x, color.y, color.z);
	return (m);
}