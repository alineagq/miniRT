/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_length_squared.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 22:28:14 by aqueiroz          #+#    #+#             */
/*   Updated: 2024/03/15 22:31:18 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvector.h"

double	vector_length_sqd(const t_vector vector)
{
	return ((vector.x * vector.x)
		+ (vector.y * vector.y)
		+ (vector.z * vector.z));
}
