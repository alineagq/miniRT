/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:46:16 by fsuomins          #+#    #+#             */
/*   Updated: 2023/11/11 10:59:15 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
	{
		clear_objects();
		mlx_close_window(mlx);
	}
}

void	init_resolution(void)
{
	t_data	*data;

	data = get_data();
	data->mlx.width = WIDTH;
	data->mlx.height = HEIGHT;
	data->viewport = flat;
	data->mlx.mlx = mlx_init(data->mlx.width, data->mlx.height, "miniRT", 0);
	data->ratio = (double)data->mlx.width / (double)data->mlx.height;
	data->mlx.image = mlx_new_image(data->mlx.mlx, data->mlx.width,
			data->mlx.height);
}

void	window_loop(void)
{
	// mlx_image_to_window(get_data()->mlx.mlx, get_data()->mlx.image, 0, 0);
	mlx_loop_hook(get_data()->mlx.mlx, &hook, get_data()->mlx.mlx);
	mlx_loop(get_data()->mlx.mlx);
	mlx_terminate(get_data()->mlx.mlx);
	clear_objects();
}
