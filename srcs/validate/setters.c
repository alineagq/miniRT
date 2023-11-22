/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 21:28:42 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/11/19 21:29:55 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_mat4	transform_cy_pl(t_vector a, t_vector center, t_mat4 scale)
{
	t_mat4	translation_by_rot;
	t_mat4	transformed_cy;
	t_mat4	orientation_to_matr;
	t_mat4	translation_matr;

	translation_matr = translation_matrix(center);
	orientation_to_matr = get_orientation(a);
	translation_by_rot = multiply_matrix(translation_matr, orientation_to_matr);
	transformed_cy = multiply_matrix(translation_by_rot, scale);
	return (transformed_cy);
}
