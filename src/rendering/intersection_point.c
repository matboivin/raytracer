/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_point.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:32:12 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/20 14:04:30 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function computes the intersection point
**
** intersection point = ray origin + t * ray direction
*/

t_vec3		get_intersection_point(t_vec3 origin, double t, t_vec3 dir)
{
	t_vec3	result;

	result = add_vec3(origin, scale_vec3(t, dir));
	return (result);
}
