/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:32:12 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/25 01:38:22 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function traces rays from the hit object to light spots to retrieve the
** final color.
*/

static t_color	trace_secondary_ray(t_scene *scene, t_ray *ray, t_lstobj *hit_obj)
{
	t_lstlight	*head;
	t_color		obj_color;
	t_color		final_color;
	t_vec3		hit_p;
	t_vec3		normal;
	t_vec3		light_dir;
	double		angle;

	final_color = create_vec3(0.0, 0.0, 0.0);
	hit_p = get_hit_point(ray->origin, ray->t_nearest, ray->dir);
	normal = get_obj_normal(hit_p, hit_obj);
	obj_color = get_obj_color(hit_obj);
	head = scene->lights;
	while (scene->lights)
	{
		light_dir = sub_vec3(scene->lights->light->pos, hit_p);
		angle = dot_vec3(normal, normalize_vec3(light_dir));
		if (angle > 0.0)
		{
			final_color = scale_vec3(fabs(angle), obj_color);
		}
		else
			final_color = create_vec3(0.0, 0.0, 0.0);
		scene->lights = scene->lights->next;
	}
	scene->lights = head;
	return (final_color);
}

/*
** This function traces a ray from the camera and checks whether this ray
** intersects any object in the scene.
** It iterates over all the objects and returns a pointer to the nearest
** intersected object. Otherwise, a null pointer is returned.
*/

static t_lstobj	*trace_primary_ray(t_scene *scene, t_ray *ray)
{
	t_lstobj	*nearest_obj;
	t_lstobj	*head;

	nearest_obj = NULL;
	head = scene->objs;
	while (scene->objs)
	{
		if (intersect(scene->objs, ray) == true)
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

t_color			trace_ray(t_scene *scene, t_ray *ray)
{
	t_color		default_color;
	t_color		hit_color;
	t_lstobj	*hit_obj;

	default_color = create_vec3(255.0, 255.0, 255.0);
	hit_obj = trace_primary_ray(scene, ray);
	if (hit_obj)
	{
		hit_color = trace_secondary_ray(scene, ray, hit_obj);
		return (hit_color);
	}
	return (default_color);
}
