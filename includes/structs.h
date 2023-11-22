/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:05:52 by fsuomins          #+#    #+#             */
/*   Updated: 2023/11/20 21:28:54 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "enums.h"

typedef struct s_material
{
	double				ambient;
	double				diffuse;
	double				specular;
	double				shininess;
	t_vector			color;
}						t_material;

typedef struct s_bhask
{
	double				a;
	double				b;
	double				c;
	double				discriminant;
	double				s1;
	double				s2;
}						t_bhask;
typedef struct s_mat4
{
	double				matrix[4][4];
	int					rows;
	int					cols;
}						t_mat4;

typedef struct s_sphere
{
	t_vector			origin;
	double				diameter;
	t_vector			color;
	t_vector			center;
	double				radius;
	t_mat4				transform;
	t_mat4				invert;
	t_material			material;
}						t_sphere;

typedef struct s_plane
{
	t_vector			origin;
	t_vector			direction;
	t_vector			color;
	t_mat4				transform;
	t_mat4				invert;
	t_material			material;
}						t_plane;

typedef struct s_cylinder
{
	t_vector			origin;
	t_vector			direction;
	double				diameter;
	double				min;
	double				max;
	double				height;
	double				radius;
	t_vector			color;
	t_mat4				transform;
	t_mat4				invert;
	t_material			material;
}						t_cylinder;

typedef struct s_inter_point
{
	int					hit_times;
	double				hit[2];
}						t_inter_point;

typedef struct s_mlx
{
	mlx_t				*mlx;
	mlx_image_t			*image;
	int					width;
	int					height;
}						t_mlx;

typedef struct s_viewport
{
	double				width;
	double				height;
	double				pixel_size;
	t_mat4				transform;
	t_mat4				inverse;
}						t_viewport;

typedef struct s_camera
{
	t_vector			origin;
	t_vector			direction;
	double				fov;
	t_viewport			viewport;
}						t_camera;

typedef struct s_ambient
{
	double				ratio;
	t_vector			color;
}						t_ambient;

typedef struct s_light
{
	t_vector			origin;
	double				ratio;
	t_vector			color;
	t_vector			dir;
	int					angle;
}						t_light;

typedef struct s_object
{
	t_shape_id			id;
	void				*object;
	struct s_object		*next;
}				
		t_object;

typedef t_object		t_hit;

typedef struct s_intersect
{
	double				id;
	t_hit				*object;
	struct s_intersect	*next;
}						t_intersect;


typedef struct s_comps
{
	int					inside;
	double				t;
	t_object			*object;
	t_vector			point;
	t_vector			over_point;
	t_vector			eyev;
	t_vector			normalv;
}						t_comps;

typedef struct s_ray
{
	t_vector			origin;
	t_vector			direction;
}						t_ray;

typedef struct s_parse
{
	char				*id;
	int					(*validate)(char *);
	int					flag;
}						t_parse;

typedef struct s_file
{
	char				*line;
	int					fd;
	int					valid;
}						t_file;
typedef struct s_data
{
	t_mlx				mlx;
	t_camera			camera;
	t_ambient			ambient;
	t_light				light;
	t_cylinder			cylinder;
	t_plane				plane;
	t_sphere			sphere;
	t_object			*objects;
}						t_data;

#endif