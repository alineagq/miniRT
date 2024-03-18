/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 02:42:45 by aqueiroz          #+#    #+#             */
/*   Updated: 2024/03/16 15:17:05 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "../libs/libvector/libvector.h"
# include "scene.h"

# define AMBIENT 0
# define DIFFUSE 1
# define SPECULAR 2
# define RESULT 3

typedef struct s_ray
{
	t_vector		origin;
	union
	{
		t_vector	direction;
		t_vector	dir;
	};
}					t_ray;

typedef struct s_variation
{
	double			min;
	double			max;
}					t_variation;

typedef struct s_hit_record
{
	t_vector		point;
	t_vector		normal;
	double			t;
	int				front_face;
	int				index;
	int				ignore_index;
}					t_hit_record;

typedef struct s_hit
{
	union
	{
		void		*object;
		t_sphere	*sphere;
		t_cylinder	*cyl;
		t_plane		*plane;
	};
	t_ray			*ray;
	t_variation		t;
	t_hit_record	*rec;
}					t_hit;

void				render(void);
void				camera_on(t_camera *camera);
t_vector			ray_color(t_ray ray, t_object *world, t_light light);
t_vector			ray_at(t_ray ray, double t);
t_vector			lighting(t_material m, t_light light, t_hit *hit,
						int in_shadow);

#endif