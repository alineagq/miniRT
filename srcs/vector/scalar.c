/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:42:54 by fsuomins          #+#    #+#             */
/*   Updated: 2023/11/09 16:43:15 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_vector	vec_sub_scalar(t_vector vec, double scalar)
{
	t_vector	result;

	result.x = vec.x - scalar;
	result.y = vec.y - scalar;
	result.z = vec.z - scalar;
	return (result);
}

t_vector	vec_add_scalar(t_vector vec, double scalar)
{
	t_vector	result;

	result.x = vec.x + scalar;
	result.y = vec.y + scalar;
	result.z = vec.z + scalar;
	return (result);
}