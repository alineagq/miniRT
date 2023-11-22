/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identity_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:22:22 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/11/19 12:30:29 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_mat4	identity_matrix(void)
{
	t_mat4	matrix;
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
			matrix.matrix[i][j++] = 0;
		matrix.matrix[i][i] = 1;
		matrix.rows = 4;
		matrix.cols = 4;
		i++;
	}
	return (matrix);
}
