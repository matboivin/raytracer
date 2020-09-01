/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_rev_normals.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 01:01:23 by mboivin           #+#    #+#             */
/*   Updated: 2020/09/01 01:44:44 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vcolor		color_rev_normals(t_ray *ray)
{
	t_vcolor	color;

	color = create_vec3(
		floor(fmax(0.0, -ray->normal.x) * 255),
		floor(fmax(0.0, -ray->normal.y) * 255),
		floor(fmax(0.0, -ray->normal.z) * 255));
	return (color);
}
