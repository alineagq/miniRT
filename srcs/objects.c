/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 21:43:53 by fsuomins          #+#    #+#             */
/*   Updated: 2023/11/07 22:23:33 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

size_t	get_obj_size(t_id id)
{
	const size_t	sizes[] = {0, 0, 0, 0, 0, sizeof(t_sphere), sizeof(t_plane),
		sizeof(t_cylinder), sizeof(t_cylinder)};

	if (id >= R && id <= tr)
		return (sizes[id]);
	return (0);
}

void	*get_obj_content(t_id id)
{
	if (id == pl)
		return (&get_data()->plane);
	return (NULL);
}

void	add_object(t_id id, void *content)
{
	t_object	*head;
	t_object	*new;
	void		*copy;

	copy = ft_calloc(1, get_obj_size(id));
	ft_memcpy(copy, content, get_obj_size(id));
	head = get_data()->objects;
	if (!head)
	{
		new = malloc(sizeof(t_object));
		new->id = id;
		new->object = copy;
		new->next = NULL;
		get_data()->objects = new;
	}
	else
	{
		if (head->next)
			while (head->next)
				head = head->next;
		new = malloc(sizeof(t_object));
		new->id = id;
		new->object = copy;
		new->next = NULL;
		head->next = new;
	}
}

void	remove_object(t_id id)
{
	t_object	*head;
	t_object	*prev;

	head = get_data()->objects;
	if (head->id == id)
	{
		get_data()->objects = head->next;
		free(head);
		return ;
	}
	while (head->next)
	{
		prev = head;
		head = head->next;
		if (head->id == id)
		{
			prev->next = head->next;
			free(head);
			return ;
		}
	}
}

void	clear_objects(void)
{
	t_object	*head;
	t_object	*tmp;

	head = get_data()->objects;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp->object);
		free(tmp);
	}
	get_data()->objects = NULL;
}
