/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:32:12 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/18 13:34:33 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function returns true if a ray intersects any object
*/

bool		hit(t_obj *objs, t_ray *ray, double *t)
{
	bool	has_hit;

	has_hit = false;
	if (objs->id == SPHERE)
		has_hit = hit_sphere(objs->data, ray, t);
	else if (objs->id == PLANE)
		has_hit = hit_plane(objs->data, ray, t);
	else if (objs->id == SQUARE)
		has_hit = hit_square(objs->data, ray, t);
	else if (objs->id == CYLINDER)
		has_hit = hit_cylinder(objs->data, ray, t);
	else if (objs->id == TRIANGLE)
		has_hit = hit_triangle(objs->data, ray, t);
	return (has_hit);
}
