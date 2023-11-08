/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:51:03 by fsuomins          #+#    #+#             */
/*   Updated: 2023/11/08 19:23:56 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

// function percorre 'objects' e chama a função de cada objeto para contruir o
// box que envolve o objeto

// void	draw_sphere(t_object sphere, void *mlx_ptr, void *win_ptr)
// {
// 	int	radius;

// 	radius = sphere.diameter / 2;
// 	int x, y, z;
// 	for (x = -radius; x <= radius; x++)
// 	{
// 		for (y = -radius; y <= radius; y++)
// 		{
// 			for (z = -radius; z <= radius; z++)
// 			{
// 				if (x * x + y * y + z * z <= radius * radius)
// 				{
// 					mlx_pixel_put(mlx_ptr, win_ptr, sphere.origin.x + x,
// 						sphere.origin.y + y, 0xFFFFFF);
// 				}
// 			}
// 		}
// 	}
// }

// void	construct_sphere(t_object *sphere)
// {
// 	float	radius;

// 	radius = sphere->diameter / 2.0;
// 	sphere->volume.min.x = sphere->origin.x - radius;
// 	sphere->volume.min.y = sphere->origin.y - radius;
// 	sphere->volume.min.z = sphere->origin.z - radius;
// 	sphere->volume.max.x = sphere->origin.x + radius;
// 	sphere->volume.max.y = sphere->origin.y + radius;
// 	sphere->volume.max.z = sphere->origin.z + radius;
// 	sphere->volume.center.x = sphere->origin.x;
// 	sphere->volume.center.y = sphere->origin.y;
// 	sphere->volume.center.z = sphere->origin.z;
// }

// // Function to construct bounding boxes for all objects
// void	construct_bounding_boxes(void)
// {
// 	t_object	*head;

// 	head = get_data()->objects;
// 	while (head)
// 	{
// 		if (head->id == SPHERE)
// 			construct_sphere(head);
// 		// Add other shape construction functions for PLANE and CYLINDER here
// 		head = head->next;
// 	}
// }
