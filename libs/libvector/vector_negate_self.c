/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_negate_self.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 22:28:23 by aqueiroz          #+#    #+#             */
/*   Updated: 2024/03/15 22:32:36 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvector.h"

t_vector	vector_negate_self(t_vector *vector)
{
	vector->x *= -1;
	vector->y *= -1;
	vector->z *= -1;
	return (*vector);
}
