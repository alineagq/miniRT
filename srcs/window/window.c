/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:46:16 by fsuomins          #+#    #+#             */
/*   Updated: 2023/11/15 00:56:49 by aqueiroz         ###   ########.fr       */
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

void	create_viewport(void)
{
	t_data		*data;
	t_viewport	viewport;
	t_vector	delta;

	data = get_data();
	viewport = get_data()->camera.viewport;
	viewport.focal_length = 1.0;
	viewport.height = 2.0;
	viewport.width = viewport.height * ((double)data->mlx.width
			/ data->mlx.height);
	data->camera.origin = create_vector(0, 0, 0);
	viewport.horizontal = create_vector(viewport.width, 0, 0);
	viewport.vertical = create_vector(0, -viewport.height, 0);
	viewport.delta_u = div_scalar(viewport.horizontal, data->mlx.width);
	viewport.delta_v = div_scalar(viewport.vertical, data->mlx.height);
	delta = sub_vector(div_scalar(viewport.delta_u, 2),
			div_scalar(viewport.delta_v, 2));
	viewport.upper_left_corner = sub_vector(data->camera.origin,
			sub_vector(create_vector(0, 0, viewport.focal_length), delta));
	viewport.origin = add_vector(viewport.upper_left_corner,
			mul_scalar(add_vector(viewport.delta_u, viewport.delta_v), 0.5));
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
	t_vector	delta_u;
	t_vector	delta_v;
	t_vector	total_delta;
	t_vector	pixel_center;
	t_vector	ray_direction;
	t_ray		ray;
	t_vector	pixel_color;

	(void)param;
	if (mlx_is_key_down(get_data()->mlx.mlx, MLX_KEY_ESCAPE))
		mlx_close_window(get_data()->mlx.mlx);
	for (int j = 0; j < get_data()->mlx.height; j++)
		for (int i = 0; i < get_data()->mlx.width; i++)
		{
			delta_u = mul_scalar(get_data()->camera.viewport.delta_u, i);
			delta_v = mul_scalar(get_data()->camera.viewport.delta_v, j);
			total_delta = add_vector(delta_u, delta_v);
			pixel_center = add_vector(get_data()->camera.viewport.origin,
				total_delta);
			ray_direction = sub_vector(pixel_center, get_data()->camera.origin);
			ray = create_ray(get_data()->camera.origin, ray_direction);
			pixel_color = mul_scalar(ray_color(ray), 255.999);
			mlx_put_pixel(get_data()->mlx.image, i, j,
				rgba_to_int(pixel_color.x, pixel_color.y, pixel_color.z, 255));
		}
}

void	window_loop(void)
{
	mlx_image_to_window(get_data()->mlx.mlx, get_data()->mlx.image, 0, 0);
	mlx_loop_hook(get_data()->mlx.mlx, render_try, NULL);
	mlx_loop(get_data()->mlx.mlx);
	mlx_terminate(get_data()->mlx.mlx);
}
