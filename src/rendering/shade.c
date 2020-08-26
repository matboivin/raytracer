/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:32:12 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/26 20:29:46 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void			add_light_color(t_ray *ray, t_vcolor light_color, double angle)
{
	t_vcolor	diffuse_color;

	diffuse_color = mult_vec3(ray->obj_color, light_color);
	diffuse_color = scale_vec3(fabs(angle), diffuse_color);
	ray->vcolor = add_vec3(ray->vcolor, diffuse_color);
}

bool			is_in_shadow(t_lstobj *objs, t_ray *ray, t_vec3 light_dir)
{
	t_ray		shadow_ray;
	t_lstobj	*hit_obj;

	shadow_ray = create_ray(ray->hit_p, light_dir, norm_vec3(light_dir));
	hit_obj = trace_ray_to_objs(objs, &shadow_ray);
	if (hit_obj)
		return (false); // tmp
	return (false);
}
