/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_project.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 22:28:29 by aqueiroz          #+#    #+#             */
/*   Updated: 2024/03/15 22:33:11 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvector.h"

t_vector	vector_project(t_vector v, t_vector n)
{
	t_vector	n_scaled;
	double		dot_product;

	dot_product = vector_dot(v, n);
	n_scaled = vector_mult(n, dot_product);
	return (vector_diff(v, n_scaled));
}
