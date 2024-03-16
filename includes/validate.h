/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 22:57:37 by aqueiroz          #+#    #+#             */
/*   Updated: 2024/03/16 15:37:24 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATE_H
# define VALIDATE_H

typedef struct s_file
{
	char	*line;
	int		fd;
	int		valid;
}			t_file;

typedef struct s_parse
{
	char	*id;
	int		(*validate)(char *);
	int		flag;
}			t_parse;

void		validate_args(int argc, char **argv);
int			validate_scene(char *file);
int			validate_orientation(char *str1, char *str2, char *str3);
int			validate_color(char *line, t_vector *color);
int			validate_ambient(char *line);
int			validate_camera(char *line);
int			validate_light(char *line);
int			validate_sphere(char *line);
int			validate_plane(char *line);
int			validate_cylinder(char *line);
int		free_split(char **split);

#endif