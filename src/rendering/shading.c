/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:32:12 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/05 01:35:46 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Process shading to retrieve final color
*/

t_color		get_obj_color(t_lstobj *hit_obj)
{
	t_color	color;

	if (hit_obj->type == SPHERE)
		color = ((t_sphere *)hit_obj->obj)->color;
	else if (hit_obj->type == PLANE)
		color = ((t_plane *)hit_obj->obj)->color;
	else if (hit_obj->type == SQUARE)
		color = ((t_square *)hit_obj->obj)->color;
	else if (hit_obj->type == CYLINDER)
		color = ((t_cyl *)hit_obj->obj)->color;
	else if (hit_obj->type == TRIANGLE)
		color = ((t_tri *)hit_obj->obj)->color;
	return (color);
}

bool		is_in_shadow(void *obj, t_ray *ray)
{
	(void)obj;
	(void)ray;
	return (false);
}

t_color		shading(t_scene *scene, t_ray *ray, t_lstobj *hit_obj)
{
	t_color	final_color;
	//t_vec3	inter;
	//t_ray	shadow_ray;

	(void)scene;
	(void)ray;
	//inter = add_vec3(ray->origin, scale_vec3(ray->t_nearest, ray->dir));
	//shadow_ray.origin = inter;
	//shadow_ray.dir = light - inter;
	final_color = get_obj_color(hit_obj);
	// while (scene->objs)
	// {
	// 	if (is_in_shadow(scene->objs->obj, shadow_ray) == true)
	// 	{
	// 		final_color = ;
	// 		break ;
	// 	}
	// 	scene->objs = scene->objs->next;
	// }
	// scene->objs = scene->objs_head;
	return (final_color);
}
