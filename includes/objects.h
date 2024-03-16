/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 15:29:43 by aqueiroz          #+#    #+#             */
/*   Updated: 2024/03/16 16:20:30 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# include "../libs/libvector/libvector.h"

typedef enum e_shape
{
	SPHERE,
	PLANE,
	CYLINDER
}					t_shape;

typedef struct s_material
{
	double			ambient;
	double			diffuse;
	double			specular;
	double			shininess;
	t_vector		color;
}					t_material;

typedef struct s_sphere
{
	t_vector		center;
	double			radius;
	t_material		material;
}					t_sphere;

typedef struct s_cylinder
{
	t_vector		axis;
	t_vector		center;
	double			radius;
	double			height;
	t_vector		cap_top;
	t_vector		cap_bottom;
	t_material		material;
}					t_cylinder;

typedef struct s_plane
{
	t_vector		normal;
	t_vector		position;
	t_material		material;
}					t_plane;

typedef struct s_object
{
	union
	{
		void		*object;
		t_sphere	*sphere;
		t_cylinder	*cyl;
		t_plane		*plane;
	};
	int				index;
	t_shape			shape;
	struct s_object	*next;
}					t_object;

void				add_object(t_shape shape, void *content);
void				clear_objects(void);
t_material			default_material(t_vector color);
void				set_ambient_light(void);

#endif