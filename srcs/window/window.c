/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:46:16 by fsuomins          #+#    #+#             */
/*   Updated: 2023/11/18 18:57:32 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	set_resolution(void)
{
	t_data	*data;

	data = get_data();
	data->mlx.width = WIDTH;
	data->mlx.height = WIDTH / ASPECT_RATIO;
	if (data->mlx.height < 1)
		data->mlx.height = 1;
}

static void	set_values_on_given_col(t_mat4 *matrix, int col, t_vector v)
{
	matrix->matrix[col][0] = v.x;
	matrix->matrix[col][1] = v.y;
	matrix->matrix[col][2] = v.z;
}

t_vector	get_look_up(t_vector direction)
{
	t_vector	look_up;
	double		dot_up;

	look_up = create_vector(0, 1, 0);
	dot_up = dot(direction, look_up);
	if (fabs(dot_up - 1) < M_EPSILON)
		look_up = create_vector(1, 0, 0);
	else if (fabs(dot_up - (-1)) < M_EPSILON)
		look_up = create_vector(-1, 0, 0);
	return (look_up);
}

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

t_mat4	traslation_matrix(t_vector v)
{
	t_mat4	traslation;

	traslation = create_identity_matrix();
	traslation.matrix[0][3] = v.x;
	traslation.matrix[1][3] = v.y;
	traslation.matrix[2][3] = v.z;
	return (traslation);
}

double get_determinant(t_mat4 m)
{
	double	determinant;
	double	cofactor;
	int		i;

	determinant = 0;
	i = 0;
	while (i < m.cols)
	{
		cofactor = m.matrix[0][i] * get_cofactor(m, 0, i);
		determinant += cofactor;
		i++;
	}
	return (determinant);
}

t_mat4	get_cofactors(t_mat4 m)
{
	t_mat4	cofactors;
	int		i;
	int		j;

	cofactors = create_identity_matrix();
	i = 0;
	while (i < m.rows)
	{
		j = 0;
		while (j < m.cols)
		{
			cofactors.matrix[i][j] = get_cofactor(m, i, j);
			j++;
		}
		i++;
	}
	return (cofactors);
}

t_mat4	inverse_matrix(t_mat4 m)
{
	t_mat4	inverse;
	t_mat4	cofactors;
	double	determinant;
	int		i;
	int		j;

	determinant = get_determinant(m);
	if (determinant == 0)
		return (m);
	cofactors = get_cofactors(m);
	inverse = create_identity_matrix();
	i = 0;
	while (i < m.rows)
	{
		j = 0;
		while (j < m.cols)
		{
			inverse.matrix[i][j] = cofactors.matrix[i][j] / determinant;
			j++;
		}
		i++;
	}
	return (inverse);
}

void	create_viewport(void)
{
	t_vector	left_pixel;
	t_vector	negate;
	t_mat4		orientation;
	t_vector	look_up;
	t_vector	up;
	t_mat4		viewport;

	negate = mul_scalar(get_data()->camera.origin, -1);
	orientation = create_identity_matrix();
	look_up = get_look_up(get_data()->camera.direction);
	left_pixel = cross(&look_up, &get_data()->camera.direction);
	up = cross(&left_pixel, &get_data()->camera.direction);
	set_values_on_given_col(&orientation, 0, left_pixel);
	set_values_on_given_col(&orientation, 1, up);
	set_values_on_given_col(&orientation, 2,
		mul_scalar(get_data()->camera.direction, -1));
	viewport = traslation_matrix(negate);
	get_data()->camera.viewport.transform = multiply_matrix(orientation, viewport);
	get_data()->camera.viewport.inverse = inverse_matrix(get_data()->camera.viewport.transform);
}

void	init_resolution(void)
{
	t_data	*data;

	data = get_data();
	set_resolution();
	create_viewport();
	data->mlx.mlx = mlx_init(data->mlx.width, data->mlx.height, "MiniRT", 0);
	data->mlx.image = mlx_new_image(data->mlx.mlx, data->mlx.width,
		data->mlx.height);
}

void	render_try(void *param)
{
	(void)param;
	if (mlx_is_key_down(get_data()->mlx.mlx, MLX_KEY_ESCAPE))
		mlx_close_window(get_data()->mlx.mlx);
}

void	window_loop(void)
{
	mlx_image_to_window(get_data()->mlx.mlx, get_data()->mlx.image, 0, 0);
	mlx_loop_hook(get_data()->mlx.mlx, render_try, NULL);
	mlx_loop(get_data()->mlx.mlx);
	mlx_terminate(get_data()->mlx.mlx);
}
