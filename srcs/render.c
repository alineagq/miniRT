/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 19:22:26 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/11/18 19:37:56 by aqueiroz         ###   ########.fr       */
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
	t_vector		pixel;
	t_vector		origin;
	t_vector		direction;
	t_vector		canvas_point;

	canvas_point = create_vector(get_world_x(cam, x), get_world_y(cam, y), -1);
	pixel = matr_product_to_point(cam.viewport.inverse, canvas_point);
	origin = matr_product_to_point(cam.viewport.inverse, create_vector(0, 0, 0));
	direction = unit_vector(sub_vector(pixel, origin));
	return (create_ray(origin, direction));
}

static void	render_world(void)
{
	int		x;
	int		y;
	t_ray	ray;
	t_vector	color;

	y = 0;
	while (y < (WIDTH / ASPECT_RATIO))
	{
		x = 0;
		while (x < WIDTH)
		{
			ray = ray_for_pixel(get_data()->camera, x, y);
			color = color_at(ray);
			mlx_img_pix_put(&get_data()->mlx.image, x, y, rgb_color(color));
			x++;
		}
		y++;
	}
}

int	render(t_data data)
{
	t_data	*data;

	data = get_data();
	render_world();
	mlx_put_image_to_window(data.mlx.mlx, data.mlx.image, 0, 0);
	return (0);
}
