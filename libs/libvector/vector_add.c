/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 22:19:06 by aqueiroz          #+#    #+#             */
/*   Updated: 2024/03/15 22:38:17 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvector.h"

t_vector	vector_add(t_vector vector, double value)
{
	t_vector	new;

	new.x = vector.x + value;
	new.y = vector.y + value;
	new.z = vector.z + value;
	return (new);
}
