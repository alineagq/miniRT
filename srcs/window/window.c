/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:46:16 by fsuomins          #+#    #+#             */
/*   Updated: 2023/11/22 13:10:50 by aqueiroz         ###   ########.fr       */
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

void	init_resolution(void)
{
	t_mlx	*mlx;

	mlx = &get_data()->mlx;
	set_resolution();
	mlx->mlx = mlx_init(mlx->width, mlx->height, "MiniRT", 0);
	mlx->image = mlx_new_image(mlx->mlx, mlx->width, mlx->height);
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
