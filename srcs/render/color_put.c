/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:06:37 by fsuomins          #+#    #+#             */
/*   Updated: 2023/11/14 11:10:35 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

unsigned int	rgb_to_data(const t_color color)
{
	int	r;
	int	g;
	int	b;

	r = (double)(color.r);
	g = (double)(color.g);
	b = (double)(color.b * 255);
	return (r << 16 | g << 8 | b);
}

void	calculate_color(mlx_image_t **image, int u, int v, t_color color)
{
	mlx_put_pixel(*image, u, v, rgb_to_data(color));
}

void	write_color(mlx_image_t **image, int u, int v, t_color color)
{
	calculate_color(image, u, v, color);
}
