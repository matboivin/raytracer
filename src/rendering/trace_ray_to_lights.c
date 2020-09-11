/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray_to_lights.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:32:12 by mboivin           #+#    #+#             */
/*   Updated: 2020/09/11 22:19:17 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		add_light(t_vcolor *output, t_vcolor light_color, double ratio)
{
	*output = add_vec3(*output, scale_vec3(ratio, light_color));
}

static bool		is_in_shadow(t_lstobj *objs, t_ray *ray, t_vec3 light_dir)
{
	t_lstobj	*cursor;
	t_ray		shadow_ray;
	double		t;

	t = norm_vec3(light_dir);
	shadow_ray = create_ray(ray->hit_p, normalize_vec3(light_dir), t);
	cursor = objs;
	while (cursor)
	{
		if (hit(cursor, &shadow_ray, &t))
		{
			if (t < shadow_ray.t_nearest)
				return (true);
		}
		cursor = cursor->next;
	}
	return (false);
}

void			compute_lighting(
	t_lstobj *objs, t_light *light, t_ray *ray, t_vcolor *output)
{
	t_vec3		light_dir;
	double		angle;
	double		coef;

	light_dir = sub_vec3(light->pos, ray->hit_p);
	angle = dot_vec3(ray->normal, normalize_vec3(light_dir));
	coef = DEFAULT_VALUE;
	if (!is_in_shadow(objs, ray, light_dir) && angle > 0.0)
	{
		coef = light->ratio * cos_vec3(ray->normal, normalize_vec3(light_dir));
		add_light(output, light->vcolor, coef);
		if (BONUS)
		{
			coef = get_specular(ray, light, light_dir, angle);
			add_light(output, light->vcolor, coef);
		}
	}
}

void			trace_ray_to_lights(t_minirt *env, t_ray *ray)
{
	t_lstlight	*cursor;
	t_vcolor	to_add;

	to_add = create_vec3(DEFAULT_VALUE, DEFAULT_VALUE, DEFAULT_VALUE);
	add_light(&to_add, env->ambient.vcolor, env->ambient.ratio);
	cursor = env->lights;
	while (cursor)
	{
		compute_lighting(env->objs, cursor->light, ray, &to_add);
		cursor = cursor->next;
	}
	ray->vcolor = mult_vec3(ray->vcolor, to_add);
}
