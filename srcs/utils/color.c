/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 00:13:03 by aqueiroz          #+#    #+#             */
/*   Updated: 2024/03/10 22:40:49 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_vector	normalize_color(t_vector color)
{
	t_vector	normalized_color;

	normalized_color.x = color.x / 255;
	normalized_color.y = color.y / 255;
	normalized_color.z = color.z / 255;
	return (normalized_color);
}

void	fix_colors(t_vector *color)
{
	if (color->x > 1)
		color->x = 1;
	if (color->y > 1)
		color->y = 1;
	if (color->z > 1)
		color->z = 1;
}

int	rgb_color(t_vector color)
{
	int	r;
	int	g;
	int	b;

	fix_colors(&color);
	color.x *= 255.999;
	color.y *= 255.999;
	color.z *= 255.999;
	r = color.x;
	g = color.y;
	b = color.z;
	return (r << 24 | g << 16 | b << 8 | 255);
}
