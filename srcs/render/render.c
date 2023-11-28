/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 19:22:26 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/11/27 21:20:58 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_ray	ray_for_pixel(t_camera cam, int x, int y)
{
	t_ray		ray;

	ray.origin = cam.origin;
	ray.direction = unit_vector(sub_vector(
		add_vector(
			add_vector(
				cam.viewport.lower_left_corner,
				mul_scalar(cam.viewport.horizontal, x)),
			mul_scalar(cam.viewport.vertical, y)),
		cam.origin));
	return (ray);
}

uint32_t	rgba_to_int(int r, int g, int b, int a)
{
	return (((uint32_t)r << 24) | ((uint32_t)g << 16) | ((uint32_t)b << 8) | a);
}

void	render(void)
{
	int			x;
	int			y;
	t_vector	normal;
	t_ray		ray;
	t_vector	color;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < (int)(WIDTH / ASPECT_RATIO))
		{
			normal.x = (double)x / (WIDTH - 1);
			normal.y = (double)y / ((WIDTH / ASPECT_RATIO) - 1);
			ray = ray_for_pixel(get_data()->camera, normal.x, normal.y);
			color = ray_color(ray);
			mlx_put_pixel(get_data()->mlx.image, x, y, rgb_color(color));
			y++;
		}
		x++;
	}
}
