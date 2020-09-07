/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_rev_normals.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 01:01:23 by mboivin           #+#    #+#             */
/*   Updated: 2020/09/07 18:36:13 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vcolor		color_rev_normals(t_ray *ray)
{
	t_vcolor	color;

	color = create_vec3(
		floor(fmax(0.0, -ray->normal.x) * MAX_RGB),
		floor(fmax(0.0, -ray->normal.y) * MAX_RGB),
		floor(fmax(0.0, -ray->normal.z) * MAX_RGB));
	return (color);
}
