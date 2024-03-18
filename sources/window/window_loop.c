/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 02:30:34 by aqueiroz          #+#    #+#             */
/*   Updated: 2024/03/16 15:01:49 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

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
