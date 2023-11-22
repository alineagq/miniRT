/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 00:18:24 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/11/20 21:11:34 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_mat4	submatrix(t_mat4 a, int row, int col)
{
	int		i;
	int		j;
	int		k;
	int		l;
	t_mat4	s_a;

	s_a.rows = a.rows - 1;
	s_a.cols = a.cols - 1;
	k = 0;
	i = -1;
	while (++i < a.rows)
	{
		l = 0;
		j = -1;
		if (i == row)
			continue ;
		while (++j < a.cols)
		{
			if (j == col)
				continue ;
			s_a.matrix[k][l++] = a.matrix[i][j];
		}
		k++;
	}
	return (s_a);
}

double	minor(t_mat4 a, int row, int col)
{
	t_mat4	sub;

	sub = submatrix(a, row, col);
	return (sub.matrix[0][0] * sub.matrix[1][1] - sub.matrix[0][1]
		* sub.matrix[1][0]);
}

double	get_cofactor(t_mat4 a, int row, int col)
{
	if (a.rows == 4 && a.cols == 4)
	{
		a = submatrix(a, row, col);
		if ((row + col) % 2 != 0)
			return (-get_determinant(a));
		return (get_determinant(a));
	}
	if ((row + col) % 2 != 0)
		return (-minor(a, row, col));
	return (minor(a, row, col));
}

int	is_invertible(t_mat4 a)
{
	int	det;

	det = get_determinant(a);
	if (det != 0)
		return (1);
	return (0);
}

double	get_determinant(t_mat4 a)
{
	int		i;
	double	cof;
	double	det;

	i = -1;
	det = 0;
	while (++i < a.cols)
	{
		cof = get_cofactor(a, 0, i);
		det += a.matrix[0][i] * cof;
	}
	return (det);
}
