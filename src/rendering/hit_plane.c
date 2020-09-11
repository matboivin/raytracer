/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 01:58:17 by mboivin           #+#    #+#             */
/*   Updated: 2020/09/11 23:09:03 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool		hit_obj_plane(t_vec3 pos, t_vec3 dir, t_ray *ray, double *t)
{
	double	denom;
	t_vec3	p;

	denom = dot_vec3(dir, ray->dir);
	if (fabs(denom) > EPSILON)
	{
		p = sub_vec3(pos, ray->origin);
		*t = dot_vec3(p, dir) / denom;
		return (*t >= EPSILON);
	}
	return (false);
}

bool		hit_plane(t_plane *plane, t_ray *ray, double *t)
{
	return (hit_obj_plane(plane->center, plane->dir, ray, t));
}
