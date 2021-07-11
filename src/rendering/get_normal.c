/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 21:56:30 by mboivin           #+#    #+#             */
/*   Updated: 2021/07/11 16:02:43 by mboivin          ###   ########.fr       */
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

/*
** This function computes sphere normal at a point
*/

t_vec3	get_sphere_normal(t_sphere *sphere, t_vec3 hit_p)
{
	return (normalize_vec3(sub_vec3(hit_p, sphere->center)));
}

/*
** This function computes 2D triangle's normal
*/

t_vec3	get_triangle_normal(t_tri *tri)
{
	t_vec3	result;

	result = cross(
		sub_vec3(tri->vertex2, tri->vertex1),
		sub_vec3(tri->vertex3, tri->vertex1));
	result = normalize_vec3(result);
	return (result);
}

/*
** This function computes cylinder normal at a point
*/

t_vec3	get_cylinder_normal(t_cyl *cylinder, t_vec3 hit_p)
{
	t_vec3	oc, result;
	double	dot_prod;

	oc = sub_vec3(hit_p, cylinder->base1);
	dot_prod = dot_vec3(cylinder->dir, oc);
	result = sub_vec3(oc, scale_vec3(dot_prod, cylinder->dir));
	result = normalize_vec3(result);
	return (result);
}
