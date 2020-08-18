/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 01:58:17 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/18 18:45:28 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function handles intersection with a sphere
** If a sphere is intersected, t_nearest is updated and true is returned.
**
** quad_coef.x = a
** quad_coef.y = b
** quad_coef.z = c
*/

bool		intersect_sphere(t_sphere *sphere, t_ray *ray)
{
	t_vec3	l;
	t_vec3	quad_coef;

	l = sub_vec3(ray->origin, sphere->pos);
	quad_coef.x = quadnorm_vec3(ray->dir);
	quad_coef.y = 2.0 * dot_vec3(ray->dir, l);
	quad_coef.z = quadnorm_vec3(l) - ft_sqr(sphere->radius);
	return (solve_quadratic(ray, quad_coef));
}
