/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:05:52 by fsuomins          #+#    #+#             */
/*   Updated: 2023/11/18 20:12:43 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_sphere
{
	t_vector			origin;
	double				diameter;
	t_vector			color;
	double				radius;
	t_mat4				transform;
	t_mat4				invert;
}						t_sphere;

typedef struct s_plane
{
	t_vector			origin;
	t_vector			direction;
	t_vector			color;
}						t_plane;

typedef struct s_cylinder
{
	t_vector			origin;
	t_vector			direction;
	t_vector			middle;
	t_vector			top;
	t_vector			bottom;
	t_vector			diff;
	double				diameter;
	double				height;
	double				half_height;
	double				radius;
	t_vector			color;
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

typedef struct s_mat4
{
	double				matrix[4][4];
	int					rows;
	int					cols;
}						t_mat4;

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

typedef struct s_intersect
{
	double				t;
	t_object			*object;
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

typedef struct s_object
{
	t_shape_id			id;
	void				*object;
	void				*next;
}						t_object;

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
	t_object			*objects;
}						t_data;

#endif