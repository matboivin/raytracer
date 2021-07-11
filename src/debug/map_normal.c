/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_normal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 01:01:23 by mboivin           #+#    #+#             */
/*   Updated: 2021/07/11 16:08:10 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "minirt.h"

t_vcolor	map_normal(t_ray *ray)
{
	t_vcolor	color;

	color = create_vec3(
		floor(fabs(ray->normal.x) * MAX_RGB),
		floor(fabs(ray->normal.y) * MAX_RGB),
		floor(fabs(ray->normal.z) * MAX_RGB));
	return (color);
}
