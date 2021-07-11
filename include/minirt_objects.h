/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_objects.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 00:58:03 by mboivin           #+#    #+#             */
/*   Updated: 2021/07/11 16:29:56 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_OBJECTS_H
# define MINIRT_OBJECTS_H

/*
** Object identifiers
*/

typedef enum	e_obj_id
{
	SPHERE,
	PLANE,
	SQUARE,
	CYLINDER,
	TRIANGLE
}				t_obj_id;

/*
** Object list
**
** id: Object identifier
** data: Pointer to object data
** next: Pointer to next object
*/

typedef struct		s_obj
{
	t_obj_id		id;
	void			*data;
	struct s_obj	*next;
}					t_obj;

/*
** Sphere
**
** center: x,y,z coordinates of the sphere center
** radius: The sphere radius (diameter / 2)
** vcolor: R,G,B colors in range [0.0,1.0]
*/

typedef struct	s_sphere
{
	t_vec3		center;
	double		radius;
	t_vcolor	vcolor;
}				t_sphere;

/*
** Plane
**
** center: x,y,z coordinates
** dir: 3D-normalized orientation vector in range [-1,1] for each x,y,z axis
** vcolor: R,G,B colors in range [0.0,1.0]
*/

typedef struct	s_plane
{
	t_vec3		center;
	t_vec3		dir;
	t_vcolor	vcolor;
}				t_plane;

/*
** Square
**
** center: x,y,z coordinates of the square center
** dir: 3D-normalized orientation vector in range [-1,1] for each x,y,z axis
** side: Size of one side
** vcolor: R,G,B colors in range [0.0,1.0]
*/

typedef struct	s_square
{
	t_vec3		center;
	t_vec3		dir;
	double		side;
	t_vcolor	vcolor;
}				t_square;

/*
** Cylinder
**
** base1: x,y,z coordinates of the cylinder bottom
** base2: x,y,z coordinates of the cylinder top
** dir: 3D-normalized orientation vector in range [-1,1] for each x,y,z axis
** radius: The cylinder radius (diameter / 2)
** height: The cylinder height
** vcolor: R,G,B colors in range [0.0,1.0]
*/

typedef struct	s_cyl
{
	t_vec3		base1;
	t_vec3		base2;
	t_vec3		dir;
	double		radius;
	double		height;
	t_vcolor	vcolor;
}				t_cyl;

/*
** Cylinder
**
** vertex1: x,y,z coordinates of the first point
** vertex2: x,y,z coordinates of the second point
** vertex3: x,y,z coordinates of the third point
** vcolor: R,G,B colors in range [0.0,1.0]
*/

typedef struct	s_tri
{
	t_vec3		vertex1;
	t_vec3		vertex2;
	t_vec3		vertex3;
	t_vec3		normal;
	t_vcolor	vcolor;
}				t_tri;

t_obj	*create_obj(void *shape_data, t_obj_id shape_id);
void	append_obj(t_obj **objs, t_obj *new_obj);
void	delete_objs(t_obj **objs);

#endif
