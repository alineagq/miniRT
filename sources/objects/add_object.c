/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 00:19:15 by aqueiroz          #+#    #+#             */
/*   Updated: 2024/03/16 02:08:58 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static void	set_node(t_object *new, t_shape shape, void *content)
{
	static int	i = 0;

	new->shape = shape;
	if (shape == SPHERE)
		new->object = (t_sphere *)content;
	else if (shape == PLANE)
		new->object = (t_plane *)content;
	else if (shape == CYLINDER)
		new->object = (t_cylinder *)content;
	new->next = NULL;
	new->index = i++;
}

void	add_object(t_shape shape, void *content)
{
	t_object	*head;
	t_object	*new;

	head = get_data()->objects;
	if (!head)
	{
		new = ft_calloc(sizeof(t_object), 1);
		set_node(new, shape, content);
		get_data()->objects = new;
	}
	else
	{
		if (head->next)
			while (head->next)
				head = head->next;
		new = ft_calloc(sizeof(t_object), 1);
		set_node(new, shape, content);
		head->next = new;
	}
}