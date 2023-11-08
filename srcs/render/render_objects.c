/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_objects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 22:44:07 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/11/08 14:15:10 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	render_sphere(t_object *object)
{
	t_sphere	*sphere;
	t_mlx		*mlx;
	int			x;
	int			y;
	int			color;

	sphere = object->object;
	mlx = get_data()->mlx;
	y = 0;
	while (y < mlx->height)
	{
		x = 0;
		while (x < mlx->width)
		{
			color = get_sphere_color(sphere, x, y);
			my_mlx_pixel_put(mlx, x, y, color);
			x++;
		}
		y++;
	}
}

