/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:09:06 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/11/19 14:10:56 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	ft_free(void *ptr)
{
	if (!ptr)
		return ;
	free(ptr);
	ptr = NULL;
}

t_intersect	*last_intersect(t_intersect *lst)
{
	if (!lst)
		return (0);
	while (lst -> next != 0)
		lst = lst -> next;
	return (lst);
}

void	intersect_add_back(t_intersect **lst, t_intersect *new)
{
	t_intersect	*last_node;

	if (lst && new)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			last_node = last_intersect(*lst);
			last_node->next = new;
		}
	}
}

void	clear_intersect(t_intersect **lst)
{
	t_intersect	*store_previous_node;

	store_previous_node = *lst;
	while (*lst != 0 && store_previous_node != 0)
	{
		store_previous_node = *lst;
		*lst = (*lst)->next;
		ft_free(store_previous_node);
	}
	lst = NULL;
}

t_intersect	*new_intersect(double t, t_hit *object)
{
	t_intersect	*new_node;

	new_node = (malloc(sizeof(t_object)));
	if (!new_node)
		return (0);
	new_node->id = t;
	new_node->object = object;
	new_node->next = NULL;
	return (new_node);
}
