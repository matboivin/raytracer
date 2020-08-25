/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   illuminate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:32:12 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/26 01:34:30 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		add_light_color(t_ray *ray, t_color light_color, double angle)
{
	t_color		diffuse_color;

	diffuse_color = mult_vec3(ray->obj_color, light_color);
	diffuse_color = scale_vec3(fabs(angle), diffuse_color);
	ray->color = add_vec3(ray->color, diffuse_color);
}

static bool		is_in_shadow(t_scene *scene, t_ray *ray, t_vec3 light_dir)
{
	t_ray		shadow_ray;
	t_lstobj	*hit_obj;

	shadow_ray = create_ray(ray->hit_p, light_dir, norm_vec3(light_dir));
	hit_obj = trace_ray_to_objs(scene, &shadow_ray);
	if (hit_obj)
		return (false); // tmp
	return (false);
}

void			illuminate(t_scene *scene, t_lstlight *lights, t_ray *ray)
{
	t_lstlight	*head;
	t_vec3		light_dir;
	double		angle;

	head = lights;
	while (lights)
	{
		light_dir = get_light_dir(lights->light->pos, ray->hit_p);
		if (is_in_shadow(scene, ray, light_dir) == false)
		{
			angle = get_angle_in(ray->normal, light_dir);
			if (angle > 0.0)
				add_light_color(ray, lights->light->color, angle);
		}
		lights = lights->next;
	}
	lights = head;
}
