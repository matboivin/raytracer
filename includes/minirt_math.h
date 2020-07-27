/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_math.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 21:32:52 by mboivin           #+#    #+#             */
/*   Updated: 2020/07/27 23:37:57 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_MATH_H
# define MINIRT_MATH_H


typedef struct	s_vec3
{
	double		x;
	double		y;
	double		z;
}				t_vec3;

t_vec3			create_vec3(double p_x, double p_y, double p_z);

t_vec3			add_vec3(t_vec3 a, t_vec3 b);
t_vec3			sub_vec3(t_vec3 a, t_vec3 b);
t_vec3			mult_vec3(t_vec3 a, t_vec3 b);
t_vec3			div_vec3(t_vec3 a, t_vec3 b);
t_vec3			scale_vec3(double scalar, t_vec3 vec);

#endif
