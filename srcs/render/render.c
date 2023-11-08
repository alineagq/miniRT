/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:54:54 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/11/08 14:14:49 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	render(void)
{
	t_data		*data;
	t_object	*object;

	data = get_data();
	object = data->objects;
	while (object)
	{
		if (object->id == SPHERE)
			render_sphere(object, data->mlx);
		// else if (object->id == PLANE)
		// 	render_plane(object);
		// else if (object->id == CYLINDER)
		// 	render_cylinder(object);
		object = object->next;
	}
}