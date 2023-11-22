/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enums.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 15:29:43 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/11/19 12:15:43 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUMS_H
# define ENUMS_H

typedef enum e_id
{
	A,
	C,
	L,
	sp,
	pl,
	cy
}	t_id;

typedef enum e_shape_id
{
	SPHERE,
	PLANE,
	CYLINDER
}	t_shape_id;

#endif