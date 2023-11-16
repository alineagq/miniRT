/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:05:52 by fsuomins          #+#    #+#             */
/*   Updated: 2023/11/14 21:23:01 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_mlx
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	int			width;
	int			height;
}				t_mlx;

typedef struct s_viewport
{
	double		focal_length;
	double		width;
	double		height;
	t_vector	u;
	t_vector	v;
	t_vector	upper_left_corner;
	t_vector	horizontal;
	t_vector	vertical;
	t_vector	delta_u;
	t_vector	delta_v;
	t_vector	origin;
}				t_viewport;

typedef struct s_camera
{
	t_vector	origin;
	t_vector	direction;
	double		fov;
	t_viewport	viewport;
}				t_camera;

typedef struct s_ray
{
	t_vector	origin;
	t_vector	direction;
}				t_ray;
typedef struct s_data
{
	t_mlx		mlx;
	t_camera	camera;
}				t_data;

#endif