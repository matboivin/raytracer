/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_obj_normal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 01:58:17 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/18 13:34:51 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	get_obj_normal(t_obj *hit_obj, t_ray *ray, t_vec3 hit_p)
{
	if (hit_obj->id == SPHERE)
		ray->normal = get_sphere_normal(hit_obj->data, hit_p);
	else if (hit_obj->id == PLANE)
		ray->normal = ((t_plane *)hit_obj->data)->dir;
	else if (hit_obj->id == SQUARE)
		ray->normal = ((t_square *)hit_obj->data)->dir;
	else if (hit_obj->id == CYLINDER)
		ray->normal = get_cylinder_normal(hit_obj->data, hit_p);
	else if (hit_obj->id == TRIANGLE)
		ray->normal = get_triangle_normal(hit_obj->data);
	if (dot_vec3(ray->dir, ray->normal) > 0.0)
		ray->normal = rev_dir_vec3(ray->normal);
}
