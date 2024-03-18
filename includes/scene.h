/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 23:09:04 by aqueiroz          #+#    #+#             */
/*   Updated: 2024/03/16 15:16:15 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "../libs/libvector/libvector.h"

typedef struct s_ambient
{
	double		ratio;
	t_vector	color;
}				t_ambient;

typedef struct s_viewport
{
	double		width;
	double		height;
	double		pixel_size;
	t_vector	view_up;
	t_vector	horizontal;
	t_vector	vertical;
	t_vector	lower_left_corner;
}				t_viewport;

typedef struct s_camera
{
	t_viewport	viewport;
	t_vector	direction;
	t_vector	origin;
	double		fov;
}				t_camera;

typedef struct s_light
{
	t_vector	origin;
	t_vector	color;
	double		ratio;
}				t_light;

#endif