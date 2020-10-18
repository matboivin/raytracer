/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_obj_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:32:12 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/18 13:35:14 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	get_obj_color(t_obj *hit_obj, t_ray *ray)
{
	if (hit_obj->id == SPHERE)
		ray->vcolor = ((t_sphere *)hit_obj->data)->vcolor;
	else if (hit_obj->id == PLANE)
		ray->vcolor = ((t_plane *)hit_obj->data)->vcolor;
	else if (hit_obj->id == SQUARE)
		ray->vcolor = ((t_square *)hit_obj->data)->vcolor;
	else if (hit_obj->id == CYLINDER)
		ray->vcolor = ((t_cyl *)hit_obj->data)->vcolor;
	else if (hit_obj->id == TRIANGLE)
		ray->vcolor = ((t_tri *)hit_obj->data)->vcolor;
}
