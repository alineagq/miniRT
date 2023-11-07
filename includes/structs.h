/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:05:52 by fsuomins          #+#    #+#             */
/*   Updated: 2023/11/07 03:11:30 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# include "minirt.h"

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
}					t_id;

typedef struct s_parse
{
	char			*id;
	int				(*validate)(char *);
	int				flag;
}					t_parse;

// Utils
typedef struct s_file
{
	char			*line;
	int				fd;
	int				valid;
}					t_file;

typedef struct s_object
{
	t_id			id;
	void			*object;
	struct s_object	*next;
}					t_object;

// Scene

typedef struct s_vector
{
	double			x;
	double			y;
	double			z;
}					t_vector;

typedef struct s_color
{
	int				r;
	int				g;
	int				b;
}					t_color;

typedef struct s_ambient
{
	double			ratio;
	t_color			color;
}					t_ambient;

typedef struct s_mat4
{
	double			data[4][4];
}					t_mat4;

typedef struct s_camera
{
	t_vector		origin;
	t_vector		direction;
	double			fov;
	double			view_range;
	t_mat4			world;
}					t_camera;

typedef struct s_light
{
	t_vector		origin;
	double			ratio;
	t_color			color;
}					t_light;

// objects

typedef struct s_sphere
{
	t_vector		origin;
	double			diameter;
	t_color			color;
	double			radius;
}					t_sphere;

typedef struct s_plane
{
	t_vector		origin;
	t_vector		direction;
	t_color			color;
}					t_plane;

typedef struct s_cylinder
{
	t_vector		origin;
	t_vector		direction;
	double			diameter;
	double			height;
	double			radius;
	t_color			color;
}					t_cylinder;

// data

typedef struct s_mlx
{
	mlx_t			*mlx;
	mlx_image_t		*image;
	void			*ptr;
	void			*win;
	int				width;
	int				height;
}					t_mlx;

typedef struct s_buffer
{
	void			*image;
	void			*address;
	int				size;
	int				width;
	int				height;
	int				bpp;
	int				row_size;
	int				endian;
	int				de_gamma;
}					t_buffer;
typedef struct s_data
{
	int				viewport;
	double			ratio;
	t_mlx			mlx;
	t_buffer		buffer;
	t_camera		camera;
	t_ambient		ambient;
	t_light			light;
	t_sphere		sphere;
	t_plane			plane;
	t_cylinder		cylinder;
	t_object		*objects;

}					t_data;

#endif