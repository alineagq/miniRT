/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inverse_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 23:53:13 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/11/20 21:05:10 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_mat4	empty_matrix(void)
{
	t_mat4	a;

	a = (t_mat4){0};
	a.rows = 4;
	a.cols = 4;
	return (a);
}

t_mat4	inverse_matrix(t_mat4 m)
{
	int		i;
	int		j;
	double	det;
	double	cof;
	t_mat4	inverted;

	i = -1;
	det = get_determinant(m);
	if (det == 0)
		return (empty_matrix());
	inverted.rows = m.rows;
	inverted.cols = m.cols;
	while (++i < m.rows)
	{
		j = -1;
		while (++j < m.cols)
		{
			cof = get_cofactor(m, i, j);
			inverted.matrix[j][i] = ((double)cof) / det;
		}
	}
	return (inverted);
}
