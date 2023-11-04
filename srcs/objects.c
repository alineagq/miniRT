/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 21:43:53 by fsuomins          #+#    #+#             */
/*   Updated: 2023/11/03 22:11:25 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	add_object(t_id id, void *content)
{
	t_object	*head;
	t_object	*new;
	void		*copy;

	copy = ft_memcpy(malloc(sizeof(content)), content, sizeof(content));
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
	t_object	*next;

	head = get_data()->objects;
	while (head)
	{
		next = head->next;
		free(head);
		head = next;
	}
	get_data()->objects = NULL;
}
