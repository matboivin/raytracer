/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 01:58:17 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/18 20:37:45 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function handles intersection with a plane
** If a plane is intersected, t_nearest is updated and true is returned.
*/

bool		intersect_plane_surface(t_vec3 center, t_vec3 dir, t_ray *ray)
{
	double	t;
	double	denom;
	t_vec3	p0l0;

	denom = dot_vec3(dir, ray->dir);
	if (fabs(denom) > 1e-6)
	{
		p0l0 = sub_vec3(center, ray->origin);
		t = dot_vec3(p0l0, dir) / denom;
		if ((t >= 0) && (t < ray->t_nearest))
		{
			ray->t_nearest = t;
			return (true);
		}
	}
	return (false);
}

bool		intersect_plane(t_plane *plane, t_ray *ray)
{
	return (intersect_plane_surface(plane->center, plane->dir, ray));
}
