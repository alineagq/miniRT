/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 12:51:05 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/11/19 13:30:19 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

size_t	get_obj_size(t_shape_id id)
{
	const size_t	size[] = {sizeof(t_sphere), sizeof(t_plane),
		sizeof(t_cylinder)};

	if (id >= SPHERE && id <= CYLINDER)
		return (size[id]);
	return (0);
}

static void	set_node(t_object *new, t_shape_id id, void *content)
{
	new->id = id;
	new->object = content;
	new->next = NULL;
}

void	add_object(t_shape_id id, void *content)
{
	t_object	*head;
	t_object	*new;
	void		*copy;

	copy = copy_content(id, content);
	head = get_data()->objects;
	if (!head)
	{
		new = ft_calloc(sizeof(t_object), 1);
		set_node(new, id, copy);
		get_data()->objects = new;
	}
	else
	{
		if (head->next)
			while (head->next)
				head = head->next;
		new = ft_calloc(sizeof(t_object), 1);
		set_node(new, id, copy);
		head->next = new;
	}
}
