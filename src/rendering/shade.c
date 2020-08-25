/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:32:12 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/26 01:16:32 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function casts a ray. If the primary ray intersects an object, a
** secondary ray is traced to process shading and retrieve final color.
** Else, default color is returned.
*/

void			shade(t_scene *scene, t_ray *ray)
{
	t_lstobj	*hit_obj;

	hit_obj = trace_ray_to_objs(scene, ray);
	if (hit_obj)
	{
		ray->obj_color = get_obj_color(hit_obj);
		ray->hit_p = get_hit_point(ray->origin, ray->t_nearest, ray->dir);
		ray->normal = get_obj_normal(hit_obj, ray, ray->hit_p);
		trace_ray_to_lights(scene, ray);
	}
}
