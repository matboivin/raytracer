/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray_to_lights.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:32:12 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/29 21:07:15 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		add_light_color(t_ray *ray, t_vcolor light_color, double coef)
{
	t_vcolor	diffuse_color;

	diffuse_color = mult_vec3(ray->obj_color, light_color);
	diffuse_color = scale_vec3(coef, diffuse_color);
	ray->vcolor = add_vec3(ray->vcolor, diffuse_color);
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
	t_vec3		light_dir;
	double		angle;
	double		coef;

	ray->vcolor = mult_vec3(ray->vcolor, env->ambient.vcolor);
	head = env->lights;
	while (env->lights)
	{
		light_dir = get_light_dir(env->lights->light->pos, ray->hit_p);
		angle = get_angle_in(ray->normal, normalize_vec3(light_dir));
		if ((is_in_shadow(env->objs, ray, light_dir) == false) && (angle > 0.0))
		{
			coef = angle / (norm_vec3(ray->normal) * norm_vec3(light_dir));
			add_light_color(ray, env->lights->light->vcolor, coef);
		}
		env->lights = env->lights->next;
	}
	env->lights = head;
}
