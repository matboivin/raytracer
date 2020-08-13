/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 00:57:27 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/13 16:48:24 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function creates a new plane
*/

t_plane			*create_plane(
	t_scene *scene, t_vec3 p_pos, t_vec3 p_rot, t_color p_color)
{
	t_plane		*result;

	result = (t_plane *)malloc(sizeof(t_plane));
	if (result == NULL)
		exit_error(scene, DEFAULT_ERR);
	result->pos = p_pos;
	result->rot = p_rot;
	result->color = p_color;
	return (result);
}
