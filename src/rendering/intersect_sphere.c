/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 01:58:17 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/07 16:55:00 by mboivin          ###   ########.fr       */
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
	double	t0;
	double	t1;

	t0 = 0; // tmp
	t1 = 1;
	(void)sphere;
	if (
		(t0 <= 0.0 && t1 <= 0.0)
		|| (t0 > ray->t_nearest && t1 > ray->t_nearest))
		return (false);
	if (t0 <= 0.0)
		t0 = t1;
	if (t1 <= 0.0)
		t1 = t0;
	ray->t_nearest = t0 < t1 ? t0 : t1;
	return (true);
}
