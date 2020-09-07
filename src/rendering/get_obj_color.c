/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_obj_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:32:12 by mboivin           #+#    #+#             */
/*   Updated: 2020/09/07 21:24:03 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	get_obj_color(t_lstobj *hit_obj, t_ray *ray)
{
	if (hit_obj->type == SPHERE)
		ray->vcolor = ((t_sphere *)hit_obj->obj)->vcolor;
	else if (hit_obj->type == PLANE)
		ray->vcolor = ((t_plane *)hit_obj->obj)->vcolor;
	else if (hit_obj->type == SQUARE)
		ray->vcolor = ((t_square *)hit_obj->obj)->vcolor;
	else if (hit_obj->type == CYLINDER)
		ray->vcolor = ((t_cyl *)hit_obj->obj)->vcolor;
	else if (hit_obj->type == TRIANGLE)
		ray->vcolor = ((t_tri *)hit_obj->obj)->vcolor;
}
