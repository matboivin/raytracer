/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 01:58:17 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/22 19:48:40 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function handles intersection with the plane of an object
*/

bool		intersect_obj_plane(t_vec3 pos, t_vec3 dir, t_ray *ray, double *t)
{
	double	dist;
	double	denom;
	t_vec3	p;

	denom = dot_vec3(dir, ray->dir);
	if (fabs(denom) > 1e-6)
	{
		p = sub_vec3(pos, ray->origin);
		dist = dot_vec3(p, dir) / denom;
		if ((dist >= 0) && (dist < ray->t_nearest))
		{
			*t = dist;
			return (true);
		}
	}
	return (false);
}

/*
** This function handles intersection with a plane
** If a plane is intersected, t_nearest is updated and true is returned
*/

bool		intersect_plane(t_plane *plane, t_ray *ray)
{
	double	t;

	if (intersect_obj_plane(plane->center, plane->dir, ray, &t) == true)
	{
		ray->t_nearest = t;
		return (true);
	}
	return (false);
}
