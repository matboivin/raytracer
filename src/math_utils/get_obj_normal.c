/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_obj_normal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 01:58:17 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/25 18:40:03 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3		get_obj_normal(t_vec3 hit_p, t_lstobj *hit_obj, t_ray *ray)
{
	t_vec3	normal;

	if (hit_obj->type == SPHERE)
		normal = get_sphere_normal(hit_p, hit_obj->obj);
	else if (hit_obj->type == PLANE)
		normal = ((t_plane *)hit_obj->obj)->dir;
	else if (hit_obj->type == SQUARE)
		normal = ((t_square *)hit_obj->obj)->dir;
	else if (hit_obj->type == CYLINDER)
		normal = get_cylinder_normal(hit_p, hit_obj->obj);
	else if (hit_obj->type == TRIANGLE)
		normal = get_triangle_normal(hit_obj->obj);
	if (dot_vec3(ray->dir, normal) > 0.0)
		normal = scale_vec3(-1, normal);
	return (normal);
}
