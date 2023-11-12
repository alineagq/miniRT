/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 21:43:53 by fsuomins          #+#    #+#             */
/*   Updated: 2023/11/12 14:05:57 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

size_t	get_obj_size(t_shape_id id)
{
	const size_t size[] = {sizeof(t_sphere), sizeof(t_plane),
		sizeof(t_cylinder)};

	if (id >= SPHERE && id <= CYLINDER)
		return (size[id]);
	return (0);
}

void	*copy_content(t_shape_id id, void *content, void *copy)
{
	if (id == SPHERE)
	{
		t_sphere *sphere = (t_sphere *)content;
		t_sphere *sphere_copy = (t_sphere *)copy;
		sphere_copy->origin = sphere->origin;
		sphere_copy->radius = sphere->radius;
		sphere_copy->color = sphere->color;
		sphere_copy->diameter = sphere->diameter;
	}
	else if (id == PLANE)
	{
		t_plane *plane = (t_plane *)content;
		t_plane *plane_copy = (t_plane *)copy;
		plane_copy->origin = plane->origin;
		plane_copy->direction = plane->direction;
		plane_copy->color = plane->color;
	}
	else if (id == CYLINDER)
	{
		t_cylinder *cylinder = (t_cylinder *)content;
		t_cylinder *cylinder_copy = (t_cylinder *)copy;
		cylinder_copy->origin = cylinder->origin;
		cylinder_copy->direction = cylinder->direction;
		cylinder_copy->radius = cylinder->radius;
		cylinder_copy->height = cylinder->height;
		cylinder_copy->color = cylinder->color;
		cylinder_copy->bottom = cylinder->bottom;
		cylinder_copy->top = cylinder->top;
		cylinder_copy->diameter = cylinder->diameter;
		cylinder_copy->diff = cylinder->diff;
		cylinder_copy->middle = cylinder->middle;
		cylinder_copy->half_height = cylinder->half_height;
	}
	return copy;  // Return the modified copy
}

void	add_object(t_shape_id id, void *content)
{
	t_object	*head;
	t_object	*new;
	void		*copy;

	copy = ft_calloc(1, get_obj_size(id));
	copy = copy_content(id, content, copy);
	head = get_data()->objects;
	if (!head)
	{
		new = ft_calloc(sizeof(t_object), 1);
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
		new = ft_calloc(sizeof(t_object), 1);
		new->id = id;
		new->object = copy;
		new->next = NULL;
		head->next = new;
	}
}

void	remove_object(t_shape_id id)
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
