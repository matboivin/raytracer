/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_triangle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 01:58:17 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/21 00:54:03 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function checks whether the intersection point vector is on the left
** side of the edge vector
*/

static bool		check_edge(t_vec3 to, t_vec3 from, t_vec3 hit_p, t_vec3 normal)
{
	t_vec3		edge;
	t_vec3		vec_p;

	edge = sub_vec3(to, from);
	vec_p = sub_vec3(hit_p, from);
	return (dot_vec3(normal, cross(edge, vec_p)) >= 0.0);
}

/*
** This function checks whether the intersection point lies in triangle
*/

static bool		is_inside_triangle(t_tri *tri, t_vec3 hit_p, t_vec3 normal)
{
	if ((check_edge(tri->vertex2, tri->vertex1, hit_p, normal) == true)
		&& (check_edge(tri->vertex3, tri->vertex2, hit_p, normal) == true)
		&& (check_edge(tri->vertex1, tri->vertex3, hit_p, normal) == true))
		return (true);
	return (false);
}

/*
** This function computes triangle's normal
*/

static t_vec3	get_triangle_normal(t_tri *tri)
{
	t_vec3		result;

	result = cross(
		sub_vec3(tri->vertex2, tri->vertex1),
		sub_vec3(tri->vertex3, tri->vertex1));
	result = normalize_vec3(result);
	return (result);
}

/*
** This function handles intersection with a triangle
** If a triangle is intersected, t_nearest is updated and true is returned.
*/

bool			intersect_triangle(t_tri *triangle, t_ray *ray)
{
	double		t;
	t_vec3		normal;
	t_vec3		hit_p;

	normal = get_triangle_normal(triangle);
	if (intersect_obj_plane(triangle->vertex1, normal, ray, &t) == true)
	{
		hit_p = get_hit_point(ray->origin, t, ray->dir);
		if (is_inside_triangle(triangle, hit_p, normal) == true)
		{
			ray->t_nearest = t;
			return (true);
		}
	}
	return (false);
}
