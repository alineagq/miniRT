/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transpose_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:30:25 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/11/19 14:30:49 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_mat4	transpose_matrix(t_mat4 a)
{
	int		i;
	int		j;
	t_mat4	t_a;

	i = 0;
	t_a.rows = a.rows;
	t_a.cols = a.cols;
	while (i < a.rows)
	{
		j = 0;
		while (j < a.cols)
		{
			t_a.matrix[i][j] = a.matrix[j][i];
			j++;
		}
		i++;
	}
	return (t_a);
}
