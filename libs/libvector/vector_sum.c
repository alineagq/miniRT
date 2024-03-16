/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_sum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 22:28:42 by aqueiroz          #+#    #+#             */
/*   Updated: 2024/03/15 22:34:19 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvector.h"

t_vector	vector_sum(t_vector vector, t_vector add)
{
	t_vector	new;

	new.x = vector.x + add.x;
	new.y = vector.y + add.y;
	new.z = vector.z + add.z;
	return (new);
}