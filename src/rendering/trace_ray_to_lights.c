/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray_to_lights.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:32:12 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/30 03:11:46 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		add_light(t_vcolor *output, t_vcolor light_color, double ratio)
{
	*output = add_vec3(*output, scale_vec3(ratio, light_color));
}

static bool		is_in_shadow(t_lstobj *objs, t_ray *ray, t_vec3 light_dir)
{
	t_ray		shadow_ray;
	t_lstobj	*hit_obj;
	double		t;

	t = norm_vec3(light_dir);
	shadow_ray = create_ray(ray->hit_p, normalize_vec3(light_dir), t);
	hit_obj = trace_ray_to_objs(objs, &shadow_ray);
	if (hit_obj)
		return (true);
	return (false);
}

void			trace_ray_to_lights(t_minirt *env, t_ray *ray)
{
	t_lstlight	*head;
	t_vcolor	to_add;
	t_vec3		light_dir;
	double		angle;

	to_add = create_vec3(0.0, 0.0, 0.0);
	add_light(&to_add, env->ambient.vcolor, env->ambient.ratio);
	head = env->lights;
	while (env->lights)
	{
		light_dir = get_light_dir(env->lights->light->pos, ray->hit_p);
		angle = fmax(0.0, dot_vec3(ray->normal, normalize_vec3(light_dir)));
		if (is_in_shadow(env->objs, ray, light_dir) == false)
		{
			add_light(&to_add, env->lights->light->vcolor, angle);
		}
		env->lights = env->lights->next;
	}
	env->lights = head;
	to_add = rescale_color(to_add, 1.0, 0.0);
	ray->vcolor = mult_vec3(ray->vcolor, to_add);
}
