/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:32:12 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/17 19:47:45 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function returns true if a ray intersects any object
*/

bool		intersect(t_lstobj *objs, t_ray *ray)
{
	bool	has_hit;

	has_hit = false;
	if (objs->type == SPHERE)
		has_hit = intersect_sphere(objs->obj, ray);
	else if (objs->type == PLANE)
		has_hit = intersect_plane(objs->obj, ray);
	else if (objs->type == SQUARE)
		has_hit = intersect_square(objs->obj, ray);
	return (has_hit);
}
