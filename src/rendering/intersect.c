/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:32:12 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/01 23:47:55 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Returns true if a ray intersects any object
*/

bool		intersect(void *obj, t_ray *ray, double *t)
{
	(void)obj;
	*t = ray->t_nearest;
	if (t)
		return (true);
	return (false);
}

/*
** When an intersection is found, the distance is tested against t_nearest
** Returns a pointer to the nearest intersected object
*/

t_lstobj	*trace(t_scene *scene, t_ray *ray)
{
	void	*nearest_obj;
	double	t;

	nearest_obj = NULL;
	while (scene->objs)
	{
		if (intersect(scene->objs->obj, ray, &t) == true)
		{
			if (t < ray->t_nearest)
			{
				ray->t_nearest = t;
				nearest_obj = scene->objs;
			}
		}
		scene->objs = scene->objs->next;
	}
	scene->objs = scene->objs_head;
	return (nearest_obj);
}
