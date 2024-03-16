/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_mult_self.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 22:28:16 by aqueiroz          #+#    #+#             */
/*   Updated: 2024/03/15 22:32:16 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvector.h"

t_vector	vector_mult_self(t_vector *vector, double value)
{
	vector->x *= value;
	vector->y *= value;
	vector->z *= value;
	return (*vector);
}
