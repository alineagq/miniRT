/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:05:52 by fsuomins          #+#    #+#             */
/*   Updated: 2023/10/18 09:36:10 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# include "minirt.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

// Scene

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}	t_vector;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_ambient
{
	double	ratio;
	t_color	*color;
}	t_ambient;

typedef struct s_camera
{
	t_vector	*origin;
	t_vector	*direction;
	double		fov;
}	t_camera;

typedef struct s_light
{
	t_vector	*origin;
	double		ratio;
	t_color		*color;
}	t_light;

// objects

typedef struct s_sphere
{
	t_vector	*origin;
	double		diameter;
	t_color		*color;
}	t_sphere;

typedef struct s_plane
{
	t_vector	*origin;
	t_vector	*direction;
	t_color		*color;
}	t_plane;

typedef struct s_cylinder
{
	t_vector	*origin;
	t_vector	*direction;
	double		diameter;
	double		height;
	t_color		*color;
}	t_cylinder;

// data

typedef struct s_data
{
	void		*mlx;
	void		*mlx_win;
	t_camera	*camera;
	t_ambient	*ambient;
	t_list		*lights;
	t_list		*objects;
}	t_data;

#endif