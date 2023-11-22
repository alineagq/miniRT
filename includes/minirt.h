/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:24:08 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/11/22 18:27:37 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../libs/MLX42/include/MLX42/MLX42.h"
# include "../libs/libft/libft.h"
# include "../libs/libvector/libvector.h"
# include "./define_rt.h"
# include "./structs.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// Data Management

t_data			*get_data(void);

// Scene Management

int				validate_scene(char *file);
void			create_viewport(void);

// Objects Management

void			clear_objects(void);

// Window Management
void			print_header(void);
void			init_resolution(void);
void			window_loop(void);

// Ray Management
t_vector		ray_at(const t_ray *r, double t);
t_vector		ray_color(const t_ray r);
t_intersect		*calculate_intersection(t_ray ray, t_hit *objects);

// Color Management
uint32_t		rgba_to_int(int r, int g, int b, int a);

// Validation
int				check_file_extention(const char *str, const char *ext);
void			print_and_exit(char *message, int exit_code);
int				validate_scene(char *file);
int				validate_ambient(char *line);
int				validate_camera(char *line);
int				validate_light(char *line);
int				validate_sphere(char *line);
int				validate_plane(char *line);
int				validate_cylinder(char *line);

// Objects Management
size_t			get_obj_size(t_shape_id id);
void			*copy_content(t_shape_id id, void *content);
void			add_object(t_shape_id id, void *content);
void			remove_object(t_shape_id id);
void			clear_objects(void);

void			init_camera(void);

// Matrix Management

t_mat4			identity_matrix(void);

// Utils
int				print_line_error(char *line);
int				validate_orientation(char *str1, char *str2, char *str3);
t_vector		color_multiply(t_vector color, double ratio);
void			free_split(char **split);
int				validate_color(char *line, t_vector *color);
t_mat4			multiply_matrix(t_mat4 a, t_mat4 b);
t_mat4			translation_matrix(t_vector v);
t_mat4			view_transform(t_vector from, t_vector forward, t_vector up);
t_mat4			inverse_matrix(t_mat4 m);
double			get_determinant(t_mat4 a);
int				is_invertible(t_mat4 a);
double			get_cofactor(t_mat4 a, int row, int col);
double			minor(t_mat4 a, int row, int col);
t_mat4			submatrix(t_mat4 a, int row, int col);
int				rgb_color(t_vector color);
t_vector		matrix_to_point(t_mat4 a);
t_mat4			vec3_to_matrix(t_vector vec);
t_mat4			point_to_matrix(t_vector point);
void			render(void);
t_mat4			scaling_matrix(t_vector x);
t_mat4			transform_object(t_vector translation, t_vector scale);
t_ray			transform_ray(t_ray ray, t_mat4 transform);
void			hit_sphere(t_ray ray, t_hit *obj, t_intersect **inters);
t_inter_point	intersect_sphere(t_ray ray, t_sphere *sphere);
void			ft_free(void *ptr);
t_intersect		*last_intersect(t_intersect *lst);
void			intersect_add_back(t_intersect **lst, t_intersect *new);
void			clear_intersect(t_intersect **lst);
t_intersect		*new_intersect(double t, t_hit *object);
t_mat4			transpose_matrix(t_mat4 a);
t_vector		normal_at(t_hit *object, t_vector world_point);
t_mat4			get_transform(t_hit *object);
t_inter_point	intersect_cylinder(t_ray ray, t_cylinder *cylinder);
void			hit_cylinder(t_ray ray, t_hit *obj, t_intersect **inters);
int				is_shadowed(t_vector point);
t_vector		lighting(t_light light, t_comps comps, t_ambient amb,
					int shadow);
t_vector		get_color(t_hit *object);
t_material		default_material(t_vector color);
t_mat4			get_orientation(t_vector a);
t_mat4			rotate_x_matrix(double radians);
t_mat4			rotate_y_matrix(double radians);
t_mat4			rotate_z_matrix(double radians);
t_mat4			transform_cy_pl(t_vector a, t_vector center, t_mat4 scale);
void			hit_plane(t_ray ray, t_hit *obj, t_intersect **inters);
t_vector		shade_hit(t_comps comps);
t_material		get_material(t_hit *object);
t_mat4			get_inv_transform(t_hit *object);
t_intersect		*hit(t_intersect *intersections);
void			init_objects(void);
void			removeDoubleSpacesAndTabs(char *str);
void			print_matrix(t_mat4 a);
t_vector		normalize_color(t_vector color);
#endif