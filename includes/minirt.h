/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:24:08 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/11/18 18:37:26 by aqueiroz         ###   ########.fr       */
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

t_data		*get_data(void);

// Window Management
void		print_header(void);
void		init_resolution(void);
void		window_loop(void);

// Ray Management
t_ray		create_ray(const t_vector origin, const t_vector direction);
t_vector	ray_at(const t_ray *r, double t);
t_vector	ray_color(const t_ray r);

// Color Management
uint32_t	rgba_to_int(uint8_t r, uint8_t g, uint8_t b, uint8_t a);

// Validation
int			check_file_extention(const char *str, const char *ext);
void		print_and_exit(char *message, int exit_code);

// Matrix Management

t_mat4		create_identity_matrix(void);

#endif