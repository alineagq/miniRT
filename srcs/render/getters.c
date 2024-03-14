/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:33:54 by aqueiroz          #+#    #+#             */
/*   Updated: 2024/03/13 20:10:51 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_vector	get_color(t_object *object)
{
	t_plane		*pl;
	t_cylinder	*cy;
	t_sphere	*sp;

	if (object->id == SPHERE)
	{
		sp = (t_sphere *)object->object;
		return (sp->material.color);
	}
	else if (object->id == CYLINDER)
	{
		cy = (t_cylinder *)object->object;
		return (cy->material.color);
	}
	else
	{
		pl = (t_plane *)object->object;
		return (pl->material.color);
	}
}

t_material	get_material(int index)
{
	t_material		material;
	t_object		*current;

	current = get_data()->objects;
	while (current)
	{
		if (index == current->index && current->id == PLANE)
			material = current->plane->material;
		else if (index == current->index && current->id == SPHERE)
			material = current->sphere->material;
		else if (index == current->index && current->id == CYLINDER)
			material = current->cyl->material;
		current = current->next;
	}
	return (material);
}

t_mat4	get_transform(t_hit *object)
{
	t_plane		*pl;
	t_cylinder	*cy;
	t_sphere	*sp;

	if (object->id == SPHERE)
	{
		sp = (t_sphere *)object->object;
		return (sp->transform);
	}
	else if (object->id == CYLINDER)
	{
		cy = (t_cylinder *)object->object;
		return (cy->transform);
	}
	else
	{
		pl = (t_plane *)object->object;
		return (pl->transform);
	}
}

t_mat4	get_inv_transform(t_hit *object)
{
	t_plane		*pl;
	t_cylinder	*cy;
	t_sphere	*sp;

	if (object->id == SPHERE)
	{
		sp = (t_sphere *)object->object;
		return (sp->invert);
	}
	else if (object->id == CYLINDER)
	{
		cy = (t_cylinder *)object->object;
		return (cy->invert);
	}
	else
	{
		pl = (t_plane *)object->object;
		return (pl->invert);
	}
}
