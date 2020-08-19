/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 01:58:17 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/20 01:17:19 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function sets y of a given 3D vector to null
*/

static t_vec3	set_vec3_ynull(t_vec3 v)
{
	t_vec3		result;

	result.x = v.x;
	result.y = 0.0;
	result.z = v.z;
	return (result);
}

/*
** This function computes cylinder's normal
*/
/*
static t_vec3	get_cylinder_normal(t_vec3 v, t_vec3 dir)
{
	t_vec3		result;
	double		dot_prod;

	dot_prod = dot_vec3(dir, v);
	result = sub_vec3(v, scale_vec3(dot_prod, dir));
	result = normalize_vec3(result);
	return (result);
}
*/

/*
** This function handles intersection with a cylinder
** If a cylinder is intersected, t_nearest is updated and true is returned.
*/

bool			intersect_cylinder(t_cyl *cylinder, t_ray *ray)
{
	t_vec3		quad_coef;
	t_vec3		inter_p;
	t_vec3		zmin;
	t_vec3		zmax;

	quad_coef = get_quad_coef(
		set_vec3_ynull(ray->origin),
		set_vec3_ynull(ray->dir),
		set_vec3_ynull(cylinder->base1),
		cylinder->radius);
	if (solve_quadratic(ray, quad_coef) == true)
	{
		inter_p = get_intersection_point(ray);
		zmin = sub_vec3(inter_p, cylinder->base1);
		zmax = sub_vec3(inter_p, cylinder->base2);
		if ((dot_vec3(cylinder->dir, zmin) > 0)
			&& (dot_vec3(cylinder->dir, zmax) < 0))
			return (true);
		reset_ray_dist(ray);
	}
	return (false);
}
