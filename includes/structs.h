/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:05:52 by fsuomins          #+#    #+#             */
/*   Updated: 2023/11/09 11:14:04 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# include "minirt.h"

typedef enum e_mat_element
{
	m_origin,
	m_forward,
	m_backward,
	m_right,
	m_left,
	m_up,
	m_down
}				t_mat_element;

typedef struct s_ray
{
	t_vector	origin;
	t_vector	direction;
	double		min;
	double		max;
}				t_ray;

typedef struct s_hit
{
	t_ray		ray;
	t_object	*ref;
	double		distance;
	t_color		color;
	t_vector	point;
	t_vector	normal;
	int			aabb_hit;
}				t_hit;

typedef enum e_shape_id
{
	SPHERE,
	PLANE,
	CYLINDER
}				t_shape_id;

typedef enum e_id
{
	R,
	A,
	c,
	l,
	sp,
	pl,
	cy,
	sq,
	tr
}				t_id;

typedef struct s_vector
{
	double		x;
	double		y;
	double		z;
}				t_vector;

typedef struct s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct s_aabb
{
	t_vector	min;
	t_vector	max;
	t_vector	center;
}				t_aabb;

typedef struct s_parse
{
	char		*id;
	int			(*validate)(char *);
	int			flag;
}				t_parse;

// Utils
typedef struct s_file
{
	char		*line;
	int			fd;
	int			valid;
}				t_file;

typedef struct s_object
{
	t_shape_id	id;
	void		*object;
	t_color		diffuse;
	t_aabb		volume;
	void		*next;
}				t_object;

typedef struct s_ambient
{
	double		ratio;
	t_color		color;
}				t_ambient;

typedef struct s_mat4
{
	double		data[4][4];
}				t_mat4;

typedef struct s_camera
{
	t_vector	origin;
	t_vector	direction;
	double		fov;
	double		view_range;
	t_mat4		world;
}				t_camera;

typedef struct s_light
{
	t_vector	origin;
	double		ratio;
	t_color		color;
}				t_light;

// objects

typedef struct s_sphere
{
	t_vector	origin;
	double		diameter;
	t_color		color;
	double		radius;
}				t_sphere;

typedef struct s_plane
{
	t_vector	origin;
	t_vector	direction;
	t_color		color;
}				t_plane;

typedef struct s_cylinder
{
	t_vector	origin;
	t_vector	direction;
	double		diameter;
	double		height;
	double		radius;
	t_color		color;
}				t_cylinder;

// data

typedef struct s_mlx
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	void		*ptr;
	void		*win;
	int			width;
	int			height;
}				t_mlx;

typedef struct s_buffer
{
	void		*image;
	void		*address;
	int			size;
	int			width;
	int			height;
	int			bpp;
	int			row_size;
	int			endian;
	int			de_gamma;
}				t_buffer;
typedef struct s_data
{
	int			viewport;
	double		ratio;
	t_mlx		mlx;
	t_buffer	buffer;
	t_camera	camera;
	t_ambient	ambient;
	t_light		light;
	t_sphere	sphere;
	t_plane		plane;
	t_cylinder	cylinder;
	t_object	*objects;
	int			u;
	int			v;

}				t_data;

#endif