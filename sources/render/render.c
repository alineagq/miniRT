/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 02:39:35 by aqueiroz          #+#    #+#             */
/*   Updated: 2024/03/16 15:46:25 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

uint32_t	color_create_rgb(t_vector *color)
{
	int	r;
	int	g;
	int	b;

	if (color->x > 1.0)
		color->x = 1.0;
	if (color->y > 1.0)
		color->y = 1.0;
	if (color->z > 1.0)
		color->z = 1.0;
	r = (int)(color->x * 255.99);
	g = (int)(color->y * 255.99);
	b = (int)(color->z * 255.99);
	if (r > 255)
		r = 255;
	if (g > 255)
		g = 255;
	if (b > 255)
		b = 255;
	if (r < 0)
		r = 0;
	if (g < 0)
		g = 0;
	if (b < 0)
		b = 0;
	return (r << 24 | g << 16 | b << 8 | 255);
}

static t_ray	ray_constructor(t_camera *camera, t_vector normal)
{
	t_ray	new;

	new.origin = camera->origin;
	new.direction = normalize(vector_diff(vector_sum(vector_sum(camera->viewport.lower_left_corner,
						vector_mult(camera->viewport.horizontal, normal.x)),
					vector_mult(camera->viewport.vertical, normal.y)),
				camera->origin));
	return (new);
}

void	render(void)
{
	t_vector	normal;
	t_vector	loop;
	t_ray		ray;
	t_vector	color;
	t_light		point_light;

	camera_on(&get_data()->camera);
	point_light = get_data()->light;
	point_light.color = vector_create(1, 1, 1);
	loop.x = 0;
	while (loop.x < WIDTH)
	{
		loop.y = 0;
		while (loop.y < HEIGHT)
		{
			normal.x = (double)loop.x / (WIDTH - 1);
			normal.y = (double)loop.y / (HEIGHT - 1);
			ray = ray_constructor(&get_data()->camera, normal);
			color = ray_color(ray, get_data()->objects, point_light);
			mlx_put_pixel(get_data()->mlx.image, loop.x, loop.y,
				color_create_rgb(&color));
			loop.y++;
		}
		loop.x++;
	}
}
