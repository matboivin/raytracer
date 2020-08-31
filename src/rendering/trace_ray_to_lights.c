/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray_to_lights.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:32:12 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/31 21:51:04 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		add_light(t_vcolor *output, t_vcolor light_color, double ratio)
{
	*output = add_vec3(*output, scale_vec3(ratio, light_color));
	*output = rescale_color(*output, 1.0, 0.0);
}

static bool		is_in_shadow(t_lstobj *objs, t_ray *ray, t_vec3 light_dir)
{
	t_lstobj	*head;
	t_ray		shadow_ray;
	double		t;

	t = norm_vec3(light_dir);
	shadow_ray = create_ray(ray->hit_p, normalize_vec3(light_dir), t, 0.001);
	head = objs;
	while (objs)
	{
		if (hit(objs, &shadow_ray) == true)
		{
			objs = head;
			return (true);
		}
		objs = objs->next;
	}
	objs = head;
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
	if (is_in_shadow(objs, ray, light_dir) == false && angle > 0.0)
	{
		coef = light->ratio * cos_vec3(ray->normal, normalize_vec3(light_dir));
		add_light(output, light->vcolor, coef);
	}
	if (is_in_shadow(objs, ray, light_dir) == false && angle > 0.0 && BONUS)
	{
		coef = get_specular(ray, light, light_dir, angle);
		add_light(output, light->vcolor, coef);
	}
}

void			trace_ray_to_lights(t_minirt *env, t_ray *ray)
{
	t_lstlight	*head;
	t_vcolor	to_add;

	to_add = create_vec3(0.0, 0.0, 0.0);
	add_light(&to_add, env->ambient.vcolor, env->ambient.ratio);
	head = env->lights;
	while (env->lights)
	{
		compute_lighting(env->objs, env->lights->light, ray, &to_add);
		env->lights = env->lights->next;
	}
	env->lights = head;
	ray->vcolor = mult_vec3(ray->vcolor, to_add);
}
