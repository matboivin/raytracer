/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 01:58:17 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/12 18:30:16 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function handles intersection with a sphere
** If a sphere is intersected, t_nearest is updated and true is returned.
**
** In Object Space, the sphere primitive default position is (0.0, 0.0, 0.0)
** If a point is on the primitive: x^2 + y^2 + z^2 = 1
*/

bool		intersect_sphere(t_sphere *sphere, t_ray *ray)
{
	t_vec3	l;
	t_vec3	center;
	double	a;
	double	b;
	double	c;

	center = create_vec3(sphere->pos.x, sphere->pos.y, sphere->pos.z);
	l = sub_vec3(ray->origin, center);
	a = quadnorm_vec3(ray->dir);
	b = 2.0 * dot_vec3(ray->dir, l);
	c = quadnorm_vec3(l) - ft_sqr(sphere->radius);
	return (solve_quadratic(ray, a, b, c));
}
