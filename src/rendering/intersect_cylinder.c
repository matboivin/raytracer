/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 01:58:17 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/18 23:41:19 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function handles intersection with a cylinder
** If a cylinder is intersected, t_nearest is updated and true is returned.
**
** quad_coef.x = a
** quad_coef.y = b
** quad_coef.z = c
*/

bool		intersect_cylinder(t_cyl *cylinder, t_ray *ray)
{
	t_vec2	ray_origin;
	t_vec2	cyl_center;
	t_vec2	l;
	t_vec3	quad_coef;

	ray_origin = create_vec2(ray->origin.x, ray->origin.y);
	cyl_center = create_vec2(cylinder->center.x, cylinder->center.y);
	l = sub_vec2(ray_origin, cyl_center);
	quad_coef.x = quadnorm_vec2(ray_origin);
	quad_coef.y = 2.0 * dot_vec2(ray_origin, l);
	quad_coef.z = quadnorm_vec2(l) - ft_sqr(cylinder->radius);
	if (solve_quadratic(ray, quad_coef) == true)
	{
		//
		reset_ray_dist(ray);
	}
	return (false);
}
