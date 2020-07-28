/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_objects.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 00:58:03 by mboivin           #+#    #+#             */
/*   Updated: 2020/07/28 13:09:41 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_OBJECTS_H
# define MINIRT_OBJECTS_H

typedef struct	s_sphere
{
	t_vec3		pos;
	double		diameter;
	t_color		color;
}				t_sphere;

typedef struct	s_plane
{
	t_vec3		pos;
	t_vec3		rot;
	t_color		color;
}				t_plane;

typedef struct	s_square
{
	t_vec3		pos;
	t_vec3		rot;
	double		side;
	t_color		color;
}				t_square;

typedef struct	s_cyl
{
	t_vec3		pos;
	t_vec3		rot;
	double		diameter;
	double		side;
	t_color		color;
}				t_cyl;

typedef struct	s_tri
{
	t_vec3		point1;
	t_vec3		point2;
	t_vec3		vec3;
	t_color		color;
}				t_tri;

void			create_sphere(t_sphere *sphere);
void			create_square(t_square *square);
void			create_plane(t_plane *plane);
void			create_cylinder(t_cyl *cylinder);
void			create_triangle(t_tri *triangle);

#endif
