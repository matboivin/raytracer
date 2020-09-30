/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_obj_normal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 01:58:17 by mboivin           #+#    #+#             */
/*   Updated: 2020/09/30 14:32:27 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	get_obj_normal(t_lstobj *hit_obj, t_ray *ray, t_vec3 hit_p)
{
	if (hit_obj->type == SPHERE)
		ray->normal = get_sphere_normal(hit_obj->obj, hit_p);
	else if (hit_obj->type == PLANE)
		ray->normal = ((t_plane *)hit_obj->obj)->dir;
	else if (hit_obj->type == SQUARE)
		ray->normal = ((t_square *)hit_obj->obj)->dir;
	else if (hit_obj->type == CYLINDER)
		ray->normal = get_cylinder_normal(hit_obj->obj, hit_p);
	else if (hit_obj->type == TRIANGLE)
		ray->normal = get_triangle_normal(hit_obj->obj);
	if (dot_vec3(ray->dir, ray->normal) > 0.0)
		ray->normal = scale_vec3(REVUNIT_VALUE, ray->normal);
}
