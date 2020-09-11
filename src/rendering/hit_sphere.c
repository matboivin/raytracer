/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 01:58:17 by mboivin           #+#    #+#             */
/*   Updated: 2020/09/11 22:09:04 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function handles intersection with a sphere
** If a sphere is intersected, t_nearest is updated and true is returned
*/

bool		hit_sphere(t_sphere *sphere, t_ray *ray, double *t)
{
	t_vec3	quad_coef;
	t_vec3	oc;
	double	root1;
	double	root2;
	bool	retvalue;

	retvalue = false;
	oc = sub_vec3(ray->origin, sphere->center);
	quad_coef = get_quad_coef(ray->dir, oc, sphere->radius);
	if (get_quad_roots(&root1, &root2, quad_coef))
	{
		if ((root1 > EPSILON) && (root1 < INFINITY))
		{
			*t = root1;
			retvalue = true;
		}
		if ((root2 > EPSILON) && (root2 < root1))
		{
			*t = root2;
			retvalue = true;
		}
	}
	return (retvalue);
}
