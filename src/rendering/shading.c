/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:32:12 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/01 18:35:51 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Process shading to retrieve final color
*/

t_color		cast_color(t_lstobj *node)
{
	t_color	color;

	if (node->type == SPHERE)
		color = ((t_sphere *)node->obj)->color;
	else if (node->type == PLANE)
		color = ((t_plane *)node->obj)->color;
	else if (node->type == SQUARE)
		color = ((t_square *)node->obj)->color;
	else if (node->type == CYLINDER)
		color = ((t_cyl *)node->obj)->color;
	else if (node->type == TRIANGLE)
		color = ((t_tri *)node->obj)->color;
	return (color);
}

t_color		shading(t_scene *scene, t_lstobj *node)
{
	t_color	final_color;

	(void)scene;
	final_color = cast_color(node);
	return (final_color);
}
