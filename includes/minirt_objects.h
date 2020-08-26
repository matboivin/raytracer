/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_objects.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 00:58:03 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/26 22:40:22 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_OBJECTS_H
# define MINIRT_OBJECTS_H

typedef enum		e_objid
{
	SPHERE,
	PLANE,
	SQUARE,
	CYLINDER,
	TRIANGLE
}					t_objid;

typedef struct		s_sphere
{
	t_vec3			center;
	double			radius;
	t_vcolor		vcolor;
}					t_sphere;

typedef struct		s_plane
{
	t_vec3			center;
	t_vec3			dir;
	t_vcolor		vcolor;
}					t_plane;

typedef struct		s_square
{
	t_vec3			center;
	t_vec3			dir;
	double			side;
	t_vcolor		vcolor;
}					t_square;

typedef struct		s_cyl
{
	t_vec3			base1;
	t_vec3			base2;
	t_vec3			dir;
	double			radius;
	double			height;
	t_vcolor		vcolor;
}					t_cyl;

typedef struct		s_tri
{
	t_vec3			vertex1;
	t_vec3			vertex2;
	t_vec3			vertex3;
	t_vec3			normal;
	t_vcolor		vcolor;
}					t_tri;

typedef struct		s_lstobj
{
	t_objid			type;
	void			*obj;
	struct s_lstobj	*next;
}					t_lstobj;

t_lstobj			*new_lstobj(void *obj, t_objid type);
void				lstobj_add_back(t_lstobj **objs, t_lstobj *new);
void				lstobj_clear(t_lstobj **objs);

#endif
