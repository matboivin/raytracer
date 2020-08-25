/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   illuminate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:32:12 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/25 23:33:25 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		add_light_color(t_ray *ray, t_light *light, double angle)
{
	t_color		light_color;

	light_color = scale_vec3(light->ratio, light->color);
	light_color = scale_vec3(fabs(angle), light_color);
	ray->color = scale_vec3(fabs(angle), ray->obj_color);
	ray->color = mult_vec3(ray->obj_color, light_color);
	ray->color = rescale_color(ray->color, 1.0, 0.0);
}

void			illuminate(t_lstlight *lights, t_ray *ray)
{
	t_lstlight	*head;
	double		angle;

	head = lights;
	while (lights)
	{
		angle = get_angle_in(lights->light->pos, ray->hit_p, ray->normal);
		if (angle > 0.0)
			add_light_color(ray, lights->light, angle);
		lights = lights->next;
	}
	lights = head;
}
