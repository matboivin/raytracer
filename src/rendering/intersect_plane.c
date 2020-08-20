/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 01:58:17 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/20 14:32:58 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function handles intersection with a plane
** If a plane is intersected, t_nearest is updated and true is returned.
*/

bool		intersect_obj_plane(t_vec3 pos, t_vec3 dir, t_ray *ray, double *t)
{
	double	tmp;
	double	denom;
	t_vec3	p0l0;

	denom = dot_vec3(dir, ray->dir);
	if (fabs(denom) > 1e-6)
	{
		p0l0 = sub_vec3(pos, ray->origin);
		tmp = dot_vec3(p0l0, dir) / denom;
		if ((tmp >= 0) && (tmp < ray->t_nearest))
		{
			*t = tmp;
			return (true);
		}
	}
	return (false);
}

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
