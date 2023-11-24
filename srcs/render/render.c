/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 19:22:26 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/11/22 20:35:27 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static double	get_world_x(t_camera camera, int x)
{
	double	x_offset;

	x_offset = (x + 0.5) * camera.viewport.pixel_size;
	return (camera.viewport.width - x_offset);
}

static double	get_world_y(t_camera camera, int y)
{
	double	y_offset;

	y_offset = (y + 0.5) * camera.viewport.pixel_size;
	return (camera.viewport.height - y_offset);
}

static t_vector	matr_product_to_point(t_mat4 a, t_vector b)
{
	t_mat4	product;
	t_mat4	b_to_matr;

	b_to_matr = point_to_matrix(b);
	product = multiply_matrix(a, b_to_matr);
	return (matrix_to_point(product));
}

t_ray	ray_for_pixel(t_camera cam, int x, int y)
{
	t_vector	pixel;
	t_vector	origin;
	t_vector	direction;
	t_vector	canvas_point;

	canvas_point = create_vector(get_world_x(cam, x), get_world_y(cam, y), -1);
	pixel = matr_product_to_point(cam.viewport.inverse, canvas_point);
	origin = matr_product_to_point(cam.viewport.inverse, create_vector(0, 0,
			0));
	direction = unit_vector(sub_vector(pixel, origin));
	return ((t_ray){origin, direction});
}

uint32_t	rgba_to_int(int r, int g, int b, int a)
{
	return (((uint32_t)r << 24) | ((uint32_t)g << 16) | ((uint32_t)b << 8) |a);
}

void	render(void)
{
	int			x;
	int			y;
	t_ray		ray;
	t_vector	color;
	uint32_t	color_int;

	y = 0;
	while (y < (int)(WIDTH / ASPECT_RATIO))
	{
		x = 0;
		while (x < WIDTH)
		{
			ray = ray_for_pixel(get_data()->camera, x, y);
			color = ray_color(ray);
			color_int = rgb_color(color);
			mlx_put_pixel(get_data()->mlx.image, x, y, color_int);
			x++;
		}
		y++;
	}
}
