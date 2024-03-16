/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_diff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 22:27:57 by aqueiroz          #+#    #+#             */
/*   Updated: 2024/03/15 22:29:55 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvector.h"

t_vector	vector_diff(t_vector u, t_vector v)
{
	t_vector	new;

	new.x = u.x - v.x;
	new.y = u.y - v.y;
	new.z = u.z - v.z;
	return (new);
}