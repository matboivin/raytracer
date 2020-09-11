/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:32:12 by mboivin           #+#    #+#             */
/*   Updated: 2020/09/11 21:50:55 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function returns true if a ray intersects any object
*/

bool		hit(t_lstobj *objs, t_ray *ray, double *t)
{
	bool	has_hit;

	has_hit = false;
	if (objs->type == SPHERE)
		has_hit = hit_sphere(objs->obj, ray, t);
	else if (objs->type == PLANE)
		has_hit = hit_plane(objs->obj, ray, t);
	else if (objs->type == SQUARE)
		has_hit = hit_square(objs->obj, ray, t);
	else if (objs->type == CYLINDER)
		has_hit = hit_cylinder(objs->obj, ray, t);
	else if (objs->type == TRIANGLE)
		has_hit = hit_triangle(objs->obj, ray, t);
	return (has_hit);
}
