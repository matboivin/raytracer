/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_normal2_rev.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 01:01:23 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/24 01:17:06 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "minirt.h"

t_vcolor		map_normal2_rev(t_ray *ray)
{
	t_vcolor	color;

	color = create_vec3(
		floor(fmax(DEFAULT_VALUE, -ray->normal.x) * MAX_RGB),
		floor(fmax(DEFAULT_VALUE, -ray->normal.y) * MAX_RGB),
		floor(fmax(DEFAULT_VALUE, -ray->normal.z) * MAX_RGB));
	return (color);
}
