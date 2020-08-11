/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 01:58:17 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/11 21:02:01 by mboivin          ###   ########.fr       */
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
	double	a;
	double	b;
	double	c;
	t_vec4	d;
	t_vec4	tmp;

	tmp = create_vec4(sphere->pos.x, sphere->pos.y, sphere->pos.z, 0);
	d = sub_vec4(ray->origin, tmp);
	a = quadnorm_vec4(ray->dir);
	b = 2 * dot_vec4(ray->dir, tmp);
	c = quadnorm_vec4(d) - pow(sphere->radius, 2);
	return (solve_quadratic(ray, a, b, c));
}
