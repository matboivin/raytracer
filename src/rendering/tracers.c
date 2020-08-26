/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:32:12 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/26 01:59:40 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void			trace_ray_to_lights(t_scene *scene, t_ray *ray)
{
	illuminate(scene, scene->lights, ray);
	ray->color = rescale_color(ray->color, 1.0, 0.0);
}

t_lstobj		*trace_ray_to_objs(t_scene *scene, t_ray *ray)
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
