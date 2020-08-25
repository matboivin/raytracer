/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_obj_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:32:12 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/25 18:40:10 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color		get_obj_color(t_lstobj *hit_obj)
{
	t_color	color;

	if (hit_obj->type == SPHERE)
		color = ((t_sphere *)hit_obj->obj)->color;
	else if (hit_obj->type == PLANE)
		color = ((t_plane *)hit_obj->obj)->color;
	else if (hit_obj->type == SQUARE)
		color = ((t_square *)hit_obj->obj)->color;
	else if (hit_obj->type == CYLINDER)
		color = ((t_cyl *)hit_obj->obj)->color;
	else if (hit_obj->type == TRIANGLE)
		color = ((t_tri *)hit_obj->obj)->color;
	return (color);
}
