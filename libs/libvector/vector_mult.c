/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_mult.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 22:28:20 by aqueiroz          #+#    #+#             */
/*   Updated: 2024/03/15 22:32:22 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvector.h"

t_vector	vector_mult(t_vector vector, double value)
{
	t_vector	new;

	new.x = vector.x * value;
	new.y = vector.y * value;
	new.z = vector.z * value;
	return (new);
}
