/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_instersection.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 13:42:13 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/11/21 00:26:35 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static void	swap_intersect_nodes(t_intersect *a, t_intersect *b)
{
	t_intersect	tmp;

	tmp = *a;
	a->id = b->id;
	a->object = b->object;
	b->id = tmp.id;
	b->object = tmp.object;
}

static void	sort_lst(t_intersect **lst)
{
	int			swapped;
	t_intersect	*curr;

	if (!lst || !(*lst))
		return ;
	while (1)
	{
		swapped = 0;
		curr = *lst;
		while (curr->next)
		{
			if (curr->id > curr->next->id)
			{
				swap_intersect_nodes(curr, curr->next);
				swapped = 1;
			}
			curr = curr->next;
		}
		if (!swapped)
			break ;
	}
}

t_intersect	*calculate_intersection(t_ray ray, t_hit *objects)
{
	t_intersect	*intersect;

	intersect = NULL;
	while (objects)
	{
		if (objects->id == SPHERE)
			hit_sphere(ray, objects, &intersect);
		else if (objects->id == CYLINDER)
			hit_cylinder(ray, objects, &intersect);
		else
			hit_plane(ray, objects, &intersect);
		objects = objects->next;
	}
	sort_lst(&intersect);
	return (intersect);
}
