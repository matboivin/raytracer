/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 01:58:17 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/11 17:31:24 by mboivin          ###   ########.fr       */
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
	double	a;
	double	b;
	double	c;
	double	discriminant;
	t_vec4	d;
	t_vec4	tmp;

	tmp = create_vec4(sphere->pos.x, sphere->pos.y, sphere->pos.z, 1);
	d = sub_vec4(ray->origin, tmp);
	a = quadnorm_vec4(ray->dir);
	b = 2 * dot_vec4(ray->dir, tmp);
	c = quadnorm_vec4(d) - pow(sphere->radius, 2);
	discriminant = pow(b, 2) - (4 * a * c);
	if (discriminant < 0)
		return (false);
	if (discriminant == 0)
	{
		ray->t_nearest = (b / a) * -0.5;
	}
	else if (discriminant > 0)
	{
		t0 = (-b + sqrt(discriminant)) / (2 * a);
		t1 = (-b - sqrt(discriminant)) / (2 * a);
		if (
			(t0 <= 0.0 && t1 <= 0.0)
			|| (t0 > ray->t_nearest && t1 > ray->t_nearest))
			return (false);
		if (t0 <= 0.0)
			t0 = t1;
		if (t1 <= 0.0)
			t1 = t0;
		ray->t_nearest = t0 < t1 ? t0 : t1;
	}
	return (true);
}
