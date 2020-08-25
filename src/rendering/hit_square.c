/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_square.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 01:58:17 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/25 22:58:53 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function checks whether the intersection point lies in square
*/

static bool	is_inside_square(t_square *square, t_vec3 hit_p)
{
	t_vec3	dist;
	double	border;

	dist = sub_vec3(hit_p, square->center);
	border = 0.5 * square->side;
	if ((fabs(dist.x) <= border)
		&& (fabs(dist.y) <= border)
		&& (fabs(dist.z) <= border))
		return (true);
	return (false);
}

/*
** This function handles intersection with a square
** If a square is intersected, t_nearest is updated and true is returned
*/

bool		hit_square(t_square *square, t_ray *ray)
{
	double	t;
	t_vec3	hit_p;

	if (hit_obj_plane(square->center, square->dir, ray, &t) == true)
	{
		hit_p = get_hit_point(ray->origin, t, ray->dir);
		if (is_inside_square(square, hit_p) == true)
		{
			ray->t_nearest = t;
			return (true);
		}
	}
	return (false);
}
