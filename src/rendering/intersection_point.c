/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_point.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:32:12 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/17 22:18:49 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function computes the intersection point
**
** intersection point = ray origin + t * ray direction
*/

t_vec3		get_intersection_point(t_ray *ray)
{
	t_vec3	result;

	result = add_vec3(ray->origin, scale_vec3(ray->t_nearest, ray->dir));
	return (result);
}
