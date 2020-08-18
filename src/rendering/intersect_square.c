/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_square.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 01:58:17 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/18 19:47:05 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function handles intersection with a square
** If a square is intersected, t_nearest is updated and true is returned.
*/

bool		intersect_square(t_square *square, t_ray *ray)
{
	t_vec3	inter_p;
	t_vec3	v;
	double	d;

	if (intersect_plane_surface(square->pos, square->dir, ray) == true)
	{
		inter_p = get_intersection_point(ray);
		v = sub_vec3(inter_p, square->pos);
		d = 0.5 * square->side;
		if ((fabs(v.x) <= d) && (fabs(v.y) <= d) && (fabs(v.z) <= d))
			return (true);
		reset_ray_dist(ray);
	}
	return (false);
}
