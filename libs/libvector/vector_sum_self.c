/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_sum_self.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 22:28:39 by aqueiroz          #+#    #+#             */
/*   Updated: 2024/03/15 22:34:05 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvector.h"

t_vector	vector_sum_self(t_vector *vector, t_vector *add)
{
	vector->x += add->x;
	vector->y += add->y;
	vector->z += add->z;
	return (*vector);
}
