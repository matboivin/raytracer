/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:32:12 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/27 22:16:54 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void			trace_ray_to_lights(t_minirt *env, t_ray *ray)
{
	t_lstlight	*head;
	t_vec3		light_dir;
	double		angle;

	head = env->lights;
	while (env->lights)
	{
		light_dir = get_light_dir(env->lights->light->pos, ray->hit_p);
		if (is_in_shadow(env->objs, ray, light_dir) == false)
		{
			angle = get_angle_in(ray->normal, normalize_vec3(light_dir));
			if (angle > 0.0)
				add_light_color(ray, env->lights->light->vcolor, angle);
		}
		env->lights = env->lights->next;
	}
	env->lights = head;
}

t_lstobj		*trace_ray_to_objs(t_lstobj *objs, t_ray *ray)
{
	t_lstobj	*nearest_obj;
	t_lstobj	*head;

	nearest_obj = NULL;
	head = objs;
	while (objs)
	{
		if (hit(objs, ray) == true)
			nearest_obj = objs;
		objs = objs->next;
	}
	objs = head;
	return (nearest_obj);
}
