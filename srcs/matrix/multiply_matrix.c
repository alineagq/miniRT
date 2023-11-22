/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiply_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 23:55:03 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/11/19 12:31:15 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_mat4	multiply_matrix(t_mat4 a, t_mat4 b)
{
	int		i;
	int		j;
	t_mat4	c;

	i = 0;
	c.rows = a.rows;
	c.cols = b.cols;
	while (i < a.rows)
	{
		j = 0;
		while (j < b.cols)
		{
			c.matrix[i][j] = (a.matrix[i][0] * b.matrix[0][j]) + (a.matrix[i][1]
					* b.matrix[1][j]) + (a.matrix[i][2] * b.matrix[2][j])
				+ (a.matrix[i][3] * b.matrix[3][j]);
			j++;
		}
		i++;
	}
	return (c);
}
