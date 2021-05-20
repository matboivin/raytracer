/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 01:58:17 by mboivin           #+#    #+#             */
/*   Updated: 2021/05/20 15:21:09 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "minirt.h"

bool		hit_sphere(t_sphere *sphere, t_ray *ray, double *t)
{
	t_vec3	quad_coef;
	t_vec3	oc;
	double	root1, root2 = INFINITY;
	bool	retval = false;

	oc = sub_vec3(ray->origin, sphere->center);
	quad_coef = get_quad_coef(ray->dir, oc, sphere->radius);
	if (get_quad_roots(&root1, &root2, quad_coef))
	{
		if ((root1 > EPSILON) && (root1 < INFINITY))
		{
			*t = root1;
			retval = true;
		}
		if ((root2 > EPSILON) && (root2 < root1))
		{
			*t = root2;
			retval = true;
		}
	}
	return (retval);
}
