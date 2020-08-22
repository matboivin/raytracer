/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_triangle_normal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 01:58:17 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/23 01:19:18 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function computes 2D triangle's normal
*/

t_vec3		get_triangle_normal(t_tri *tri)
{
	t_vec3	result;

	result = cross(
		sub_vec3(tri->vertex2, tri->vertex1),
		sub_vec3(tri->vertex3, tri->vertex1));
	result = normalize_vec3(result);
	return (result);
}
