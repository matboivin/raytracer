/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:32:12 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/12 18:42:51 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function returns true if a ray intersects any object
*/

bool			intersect(t_lstobj *objs, t_ray *ray)
{
	bool		has_hit;

	has_hit = false;
	if (objs->type == SPHERE)
		has_hit = intersect_sphere(objs->obj, ray);
	return (has_hit);
}

/*
** This function iterates over all the scene objects and tests the distance t
** against t_nearest when an intersection is found.
** Returns a pointer to the nearest intersected object.
** Otherwise, a null pointer is returned.
**
** t_nearest is reset to max double value at each ray cast.
*/

t_lstobj		*trace(t_scene *scene, t_ray *ray)
{
	t_lstobj	*nearest_obj;

	nearest_obj = NULL;
	while (scene->objs)
	{
		if (intersect(scene->objs, ray) == true)
			nearest_obj = scene->objs;
		scene->objs = scene->objs->next;
	}
	scene->objs = scene->objs_head;
	return (nearest_obj);
}
