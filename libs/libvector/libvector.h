/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libvector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:52:57 by aqueiroz          #+#    #+#             */
/*   Updated: 2024/03/14 13:25:03 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBVECTOR_H
# define LIBVECTOR_H

# include <math.h>
# include <stdio.h>

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}			t_vector;

t_vector	vector_add(t_vector vector, double value);
t_vector	vector_create(double x, double y, double z);
t_vector	vector_cross(t_vector u, t_vector v);
t_vector	vector_diff(t_vector u, t_vector v);
t_vector	vector_div_self(t_vector *vector, double value);
t_vector	vector_div(t_vector vector, double value);
double		vector_dot(t_vector u, t_vector v);
double		vector_length_sqd(const t_vector vector);
double		vector_length(t_vector vector);
t_vector	vector_mult_self(t_vector *vector, double value);
t_vector	vector_mult(t_vector vector, double value);
t_vector	vector_negate_self(t_vector *vector);
t_vector	vector_product(t_vector u, t_vector v);
t_vector	vector_project_onto_plane(t_vector v, t_vector n);
t_vector	vector_reflect(t_vector v, t_vector n);
t_vector	vector_subtr(t_vector vector, double value);
t_vector	vector_sum_self(t_vector *vector, t_vector *add);
t_vector	vector_sum(t_vector vector, t_vector add);
t_vector	vector_unit(t_vector vector);
t_vector

#endif