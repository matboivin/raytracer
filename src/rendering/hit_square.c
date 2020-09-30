/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_square.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 01:58:17 by mboivin           #+#    #+#             */
/*   Updated: 2020/09/30 16:16:10 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	is_inside_square(t_square *square, t_vec3 hit_p)
{
	t_vec3	dist;
	double	border;

	dist = sub_vec3(hit_p, square->center);
	border = square->side * HALF_DIV;
	if ((fabs(dist.x) <= border)
		&& (fabs(dist.y) <= border)
		&& (fabs(dist.z) <= border))
		return (true);
	return (false);
}

bool		hit_square(t_square *square, t_ray *ray, double *t)
{
	t_vec3	hit_p;

	hit_p = create_vec3(DEFAULT_VALUE, DEFAULT_VALUE, DEFAULT_VALUE);
	if (hit_obj_plane(square->center, square->dir, ray, t))
	{
		hit_p = get_hit_point(ray->origin, *t, ray->dir);
		return (is_inside_square(square, hit_p));
	}
	return (false);
}
