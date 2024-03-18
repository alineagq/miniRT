/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_lenght.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 22:28:11 by aqueiroz          #+#    #+#             */
/*   Updated: 2024/03/15 22:31:39 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvector.h"

double	vector_length(t_vector vector)
{
	double	length;

	length = (vector.x * vector.x)
		+ (vector.y * vector.y)
		+ (vector.z * vector.z);
	return (sqrt(length));
}