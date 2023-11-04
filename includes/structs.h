/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:05:52 by fsuomins          #+#    #+#             */
/*   Updated: 2023/11/03 21:37:01 by fsuomins         ###   ########.fr       */
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
}	t_id;

typedef struct s_parse
{
	char	*id;
	int		(*validate)(char *);
	int		flag;
}	t_parse;

// Utils
typedef struct s_file
{
	char	*line;
	int		fd;
	int		valid;
}	t_file;

typedef struct s_object
{
	t_id	id;
	void	*object;
	struct s_object	*next;
}	t_object;

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
	t_color	color;
}	t_ambient;

typedef struct s_camera
{
	t_vector	origin;
	t_vector	direction;
	double		fov;
}	t_camera;

typedef struct s_light
{
	t_vector	origin;
	double		ratio;
	t_color		color;
}	t_light;

// objects

typedef struct s_sphere
{
	t_vector	*origin;
	double		diameter;
	t_color		color;
}	t_sphere;

typedef struct s_plane
{
	t_vector	origin;
	t_vector	direction;
	t_color		color;
}	t_plane;

typedef struct s_cylinder
{
	t_vector	*origin;
	t_vector	*direction;
	double		diameter;
	double		height;
	t_color		color;
}	t_cylinder;

// data

typedef struct s_data
{
	void		*mlx;
	void		*mlx_win;
	t_camera	camera;
	t_ambient	ambient;
	t_light		light;
	t_sphere	sphere;
	t_plane		plane;
	t_cylinder	cylinder;
	t_object	*objects;
}	t_data;

#endif