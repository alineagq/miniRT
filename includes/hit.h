/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 03:28:19 by aqueiroz          #+#    #+#             */
/*   Updated: 2024/03/16 17:10:23 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HIT_H
# define HIT_H

# include "minirt.h"
# include "objects.h"
# include "scene.h"
# include "render.h"

typedef struct s_bhaskara
{
	double	a;
	double	b;
	double	c;
	double	discr;
	double	root[2];
}			t_bhaskara;

int			hit_sphere(t_sphere sphere, t_ray *ray, t_variation t,
				t_hit_record *rec);
void		set_face_normal(t_hit_record *rec, t_ray *ray,
				t_vector *out_normal);
int			hittable_list_hit(t_object *list, t_ray *ray, t_variation t,
				t_hit_record *rec);
int			hit_plane(t_plane plane, t_ray *ray, t_variation t,
				t_hit_record *rec);
int			hit_cylinder(t_cylinder *cyl, t_ray *ray, t_variation t,
				t_hit_record *rec);
t_hit		init_hit(t_cylinder *cyl, t_ray *ray, t_variation t,
				t_hit_record *rec);
t_bhaskara	init_bhaskara(t_vector pj_ori_center, t_vector v, double radius);
void		update_hit_record(t_hit_record *rec, t_vector point,
				t_vector cap_bottom, t_vector axis);
int			body_or_cap(t_hit *hit, int body_hit);
int			select_hit(double rt[2], t_hit *hit, int vld_inter1,
				int vld_inter2);

int			is_shadowed(t_vector point, t_light light, t_object *world,
				int ignored_index);
#endif