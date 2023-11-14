/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libvector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:52:57 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/11/14 15:18:22 by aqueiroz         ###   ########.fr       */
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

t_vector	create_vector(double x, double y, double z);
t_vector	negate_vector(t_vector v);
t_vector	add(const t_vector *u, const t_vector *v);
t_vector	sub(const t_vector *u, const t_vector *v);
t_vector	mul(const t_vector *u, const t_vector *v);
t_vector	div(const t_vector *u, const t_vector *v);
t_vector	add_scalar(t_vector v, double scalar);
t_vector	sub_scalar(t_vector v, double scalar);
t_vector	mul_scalar(t_vector v, double scalar);
t_vector	div_scalar(t_vector v, double scalar);
t_vector	cross(const t_vector *u, const t_vector *v);
void		add_eq(t_vector *v, const t_vector *u);
void		mul_eq(t_vector *v, double t);
void		div_eq(t_vector *v, double t);
double		length(const t_vector *v);
double		length_squared(const t_vector *v);
void		print_t_vector(const t_vector *v);
t_vector	unit_vector(t_vector v);
double		dot(const t_vector *u, const t_vector *v);

#endif