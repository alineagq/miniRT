/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:33:54 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/11/21 00:05:04 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_vector	get_color(t_hit *object)
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

t_material	get_material(t_hit *object)
{
	t_plane		*pl;
	t_cylinder	*cy;
	t_sphere	*sp;

	if (object->id == SPHERE)
	{
		sp = (t_sphere *)object->object;
		return (sp->material);
	}
	else if (object->id == CYLINDER)
	{
		cy = (t_cylinder *)object->object;
		return (cy->material);
	}
	else
	{
		pl = (t_plane *)object->object;
		return (pl->material);
	}
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
