/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 01:58:17 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/20 14:03:26 by mboivin          ###   ########.fr       */
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
** This function handles intersection with a cylinder
** If a cylinder is intersected, t_nearest is updated and true is returned.
*/

bool			intersect_cylinder(t_cyl *cylinder, t_ray *ray)
{
	t_vec3		quad_coef;

	quad_coef = get_quad_coef(
		set_vec3_ynull(ray->origin),
		set_vec3_ynull(ray->dir),
		set_vec3_ynull(cylinder->base1),
		cylinder->radius);
	if (solve_quadratic(ray, quad_coef) == true)
	{
		return (true);
	}
	return (false);
}
