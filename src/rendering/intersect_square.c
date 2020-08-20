/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_square.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 01:58:17 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/21 00:54:03 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function handles intersection with a square
** If a square is intersected, t_nearest is updated and true is returned.
*/

bool		intersect_square(t_square *square, t_ray *ray)
{
	double	t;
	t_vec3	hit_p;
	t_vec3	v;
	double	d;

	if (intersect_obj_plane(square->center, square->dir, ray, &t) == true)
	{
		hit_p = get_hit_point(ray->origin, t, ray->dir);
		v = sub_vec3(hit_p, square->center);
		d = 0.5 * square->side;
		if ((fabs(v.x) <= d) && (fabs(v.y) <= d) && (fabs(v.z) <= d))
		{
			ray->t_nearest = t;
			return (true);
		}
	}
	return (false);
}
