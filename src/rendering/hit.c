/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:32:12 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/25 22:52:45 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function returns true if a ray intersects any object
*/

bool		hit(t_lstobj *objs, t_ray *ray)
{
	bool	has_hit;

	has_hit = false;
	if (objs->type == SPHERE)
		has_hit = hit_sphere(objs->obj, ray);
	else if (objs->type == PLANE)
		has_hit = hit_plane(objs->obj, ray);
	else if (objs->type == SQUARE)
		has_hit = hit_square(objs->obj, ray);
	else if (objs->type == CYLINDER)
		has_hit = hit_cylinder(objs->obj, ray);
	else if (objs->type == TRIANGLE)
		has_hit = hit_triangle(objs->obj, ray);
	return (has_hit);
}
