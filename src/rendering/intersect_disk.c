/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_disk.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 01:58:17 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/18 23:17:46 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function handles intersection with a disk
** If a disk is intersected, t_nearest is updated and true is returned.
*/

bool		intersect_disk(t_vec3 center, t_vec3 dir, double radius, t_ray *ray)
{
	t_vec3	inter_p;
	t_vec3	v;
	double	d;

	if (intersect_obj_plane(center, dir, ray) == true)
	{
		inter_p = get_intersection_point(ray);
		v = sub_vec3(inter_p, center);
		d = quadnorm_vec3(v);
		if (d <= ft_sqr(radius))
			return (true);
		reset_ray_dist(ray);
	}
	return (false);
}
