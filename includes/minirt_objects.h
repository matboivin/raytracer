/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_objects.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 00:58:03 by mboivin           #+#    #+#             */
/*   Updated: 2020/07/23 01:02:56 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_OBJECTS_H
# define MINIRT_OBJECTS_H

typedef struct	s_sphere
{
	t_coord3	pos;
	double		diameter;
	t_color		color;
}				t_sphere;

typedef struct	s_square
{
	t_coord3	pos;
	t_coord3	rot;
	double		side;
	t_color		color;
}				t_square;

typedef struct	s_plane
{
	t_coord3	pos;
	t_coord3	rot;
	t_color		color;
}				t_plane;

typedef struct	s_cyl
{
	t_coord3	pos;
	t_coord3	rot;
	double		diameter;
	double		side;
	t_color		color;
}				t_cyl;

typedef struct	s_tri
{
	t_coord3	point1;
	t_coord3	point2;
	t_coord3	point3;
	t_color		color;
}				t_tri;

void			create_sphere(t_sphere *sphere);
void			create_square(t_square *square);
void			create_plane(t_plane *plane);
void			create_cylinder(t_cyl *cylinder);
void			create_triangle(t_tri *triangle);

#endif
