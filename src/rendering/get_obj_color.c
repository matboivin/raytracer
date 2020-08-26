/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_obj_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:32:12 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/26 19:20:30 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vcolor		get_obj_color(t_lstobj *hit_obj)
{
	t_vcolor	vcolor;

	if (hit_obj->type == SPHERE)
		vcolor = ((t_sphere *)hit_obj->obj)->vcolor;
	else if (hit_obj->type == PLANE)
		vcolor = ((t_plane *)hit_obj->obj)->vcolor;
	else if (hit_obj->type == SQUARE)
		vcolor = ((t_square *)hit_obj->obj)->vcolor;
	else if (hit_obj->type == CYLINDER)
		vcolor = ((t_cyl *)hit_obj->obj)->vcolor;
	else if (hit_obj->type == TRIANGLE)
		vcolor = ((t_tri *)hit_obj->obj)->vcolor;
	return (vcolor);
}
