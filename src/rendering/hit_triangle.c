/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_triangle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 01:58:17 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/18 16:05:42 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool		check_edge(t_vec3 to, t_vec3 from, t_vec3 hit_p, t_vec3 normal)
{
	t_vec3		edge;
	t_vec3		vec_p;

	edge = sub_vec3(to, from);
	vec_p = sub_vec3(hit_p, from);
	return (dot_vec3(normal, cross(edge, vec_p)) >= 0.0);
}

static bool		is_inside_triangle(t_tri *tri, t_vec3 hit_p, t_vec3 normal)
{
	return (
		(check_edge(tri->vertex2, tri->vertex1, hit_p, normal))
		&& (check_edge(tri->vertex3, tri->vertex2, hit_p, normal))
		&& (check_edge(tri->vertex1, tri->vertex3, hit_p, normal)));
}

bool			hit_triangle(t_tri *triangle, t_ray *ray, double *t)
{
	t_vec3		hit_p;

	hit_p = create_vec3(DEFAULT_VALUE, DEFAULT_VALUE, DEFAULT_VALUE);
	if (hit_obj_plane(triangle->vertex1, triangle->normal, ray, t))
	{
		hit_p = get_hit_point(ray->origin, *t, ray->dir);
		return (is_inside_triangle(triangle, hit_p, triangle->normal));
	}
	return (false);
}
