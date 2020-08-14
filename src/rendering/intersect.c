/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:32:12 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/14 00:31:44 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function returns true if a ray intersects any object
*/

bool			intersect(t_scene *scene, t_ray *ray)
{
	bool		has_hit;

	has_hit = false;
	if (scene->objs->type == SPHERE)
		has_hit = intersect_sphere(scene->objs->obj, ray);
	else if (scene->objs->type == PLANE)
		has_hit = intersect_plane(scene->objs->obj, ray);
	else if (scene->objs->type == SQUARE)
		has_hit = intersect_square(scene, scene->objs->obj, ray);
	return (has_hit);
}

/*
** This function iterates over all the scene objects and tests the distance t
** against t_nearest when an intersection is found.
** Returns a pointer to the nearest intersected object.
** Otherwise, a null pointer is returned.
*/

t_lstobj		*trace(t_scene *scene, t_ray *ray)
{
	t_lstobj	*nearest_obj;
	t_lstobj	*head;

	nearest_obj = NULL;
	head = scene->objs;
	while (scene->objs)
	{
		if (intersect(scene, ray) == true)
			nearest_obj = scene->objs;
		scene->objs = scene->objs->next;
	}
	scene->objs = head;
	return (nearest_obj);
}
