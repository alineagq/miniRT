/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_content.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 12:52:46 by aqueiroz          #+#    #+#             */
/*   Updated: 2024/02/14 10:03:24 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static void	*copy_sphere(t_sphere *sphere)
{
	t_sphere	*sphere_copy;

	sphere_copy = ft_calloc(sizeof(t_sphere), 1);
	sphere_copy->origin = sphere->origin;
	sphere_copy->radius = sphere->radius;
	sphere_copy->color = sphere->color;
	sphere_copy->diameter = sphere->diameter;
	return (sphere_copy);
}

static void	*copy_plane(t_plane *plane)
{
	t_plane	*plane_copy;

	plane_copy = ft_calloc(sizeof(t_plane), 1);
	plane_copy->origin = plane->origin;
	plane_copy->direction = plane->direction;
	plane_copy->color = plane->color;
	return (plane_copy);
}

static void	*copy_cylinder(t_cylinder *cylinder)
{
	t_cylinder	*cylinder_copy;

	cylinder_copy = ft_calloc(sizeof(t_cylinder), 1);
	cylinder_copy->origin = cylinder->origin;
	cylinder_copy->direction = cylinder->direction;
	cylinder_copy->radius = cylinder->radius;
	cylinder_copy->height = cylinder->height;
	cylinder_copy->color = cylinder->color;
	cylinder_copy->diameter = cylinder->diameter;
	return (cylinder_copy);
}

void	*copy_content(t_shape_id id, void *content)
{
	if (id == SPHERE)
		return (copy_sphere((t_sphere *)content));
	else if (id == PLANE)
		return (copy_plane((t_plane *)content));
	else if (id == CYLINDER)
		return (copy_cylinder((t_cylinder *)content));
	return (NULL);
}
