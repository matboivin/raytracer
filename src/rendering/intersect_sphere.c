/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 01:58:17 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/19 18:49:54 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function handles intersection with a sphere
** If a sphere is intersected, t_nearest is updated and true is returned.
*/

bool		intersect_sphere(t_sphere *sphere, t_ray *ray)
{
	t_vec3	quad_coeff;

	quad_coeff = get_quad_coeff(
		ray->origin,
		ray->dir,
		sphere->center,
		sphere->radius);
	return (solve_quadratic(ray, quad_coeff));
}
