/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:32:12 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/25 23:17:20 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		trace_secondary_ray(t_scene *scene, t_ray *ray)
{
	illuminate(scene->lights, ray);
	// add ambient, diffuse, specular
	// return later to do more intersections
	ray->color = rescale_color(ray->color, 1.0, 0.0);
}

static t_lstobj	*trace_primary_ray(t_scene *scene, t_ray *ray)
{
	t_lstobj	*nearest_obj;
	t_lstobj	*head;

	nearest_obj = NULL;
	head = scene->objs;
	while (scene->objs)
	{
		if (hit(scene->objs, ray) == true)
			nearest_obj = scene->objs;
		scene->objs = scene->objs->next;
	}
	scene->objs = head;
	return (nearest_obj);
}

/*
** This function casts a ray. If the primary ray intersects an object, a
** secondary ray is traced to process shading and retrieve final color.
** Else, default color is returned.
*/

void			shade(t_scene *scene, t_ray *ray)
{
	t_lstobj	*hit_obj;

	hit_obj = trace_primary_ray(scene, ray);
	if (hit_obj)
	{
		ray->obj_color = get_obj_color(hit_obj);
		ray->hit_p = get_hit_point(ray->origin, ray->t_nearest, ray->dir);
		ray->normal = get_obj_normal(ray->hit_p, hit_obj, ray);
		trace_secondary_ray(scene, ray);
	}
}
