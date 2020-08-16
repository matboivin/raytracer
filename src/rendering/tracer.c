/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:32:12 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/16 18:13:49 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
