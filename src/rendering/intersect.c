/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:32:12 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/16 18:14:04 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function returns true if a ray intersects any object
*/

bool		intersect(t_scene *scene, t_ray *ray)
{
	bool	has_hit;

	has_hit = false;
	if (scene->objs->type == SPHERE)
		has_hit = intersect_sphere(scene->objs->obj, ray);
	else if (scene->objs->type == PLANE)
		has_hit = intersect_plane(scene->objs->obj, ray);
	else if (scene->objs->type == SQUARE)
		has_hit = intersect_square(scene, scene->objs->obj, ray);
	return (has_hit);
}
