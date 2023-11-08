/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:54:54 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/11/08 11:59:53 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	render(void)
{
	t_data		*data;
	t_object	*objects;

	data = get_data();
	objects = data->objects;
	while (objects)
	{
		if (objects->id == sp)
			render_sphere(objects->object);
		objects = objects->next;
	}
}
