/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:32:12 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/25 20:00:00 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void			illuminate(t_lstlight *lights, t_ray *ray)
{
	t_lstlight	*head;
	double		angle;

	head = lights;
	while (lights)
	{
		angle = get_angle_in(lights->light->pos, ray->hit_p, ray->normal);
		if (angle > 0.0)
		{
			ray->color = scale_vec3(fabs(angle), ray->obj_color);
		}
		lights = lights->next;
	}
	lights = head;
}
