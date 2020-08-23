/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_obj_normal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 01:58:17 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/24 00:48:56 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3		get_obj_normal(t_vec3 hit_p, t_lstobj *hit_obj)
{
	t_vec3	normal;

	if (hit_obj->type == SPHERE)
		normal = get_sphere_normal(hit_p, ((t_sphere *)hit_obj->obj)->center);
	else if (hit_obj->type == PLANE)
		normal = ((t_plane *)hit_obj->obj)->dir;
	else if (hit_obj->type == SQUARE)
		normal = ((t_square *)hit_obj->obj)->dir;
	else if (hit_obj->type == CYLINDER)
		normal = get_cylinder_normal(hit_p, hit_obj->obj);
	else if (hit_obj->type == TRIANGLE)
		normal = get_triangle_normal(hit_obj->obj);
	return (normal);
}
