/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cylinder_normal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 01:58:17 by mboivin           #+#    #+#             */
/*   Updated: 2020/09/11 22:12:51 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function computes cylinder normal at a point
*/

t_vec3		get_cylinder_normal(t_cyl *cylinder, t_vec3 hit_p)
{
	t_vec3	oc;
	t_vec3	result;
	double	dot_prod;

	oc = sub_vec3(hit_p, cylinder->base1);
	dot_prod = dot_vec3(cylinder->dir, oc);
	result = sub_vec3(oc, scale_vec3(dot_prod, cylinder->dir));
	result = normalize_vec3(result);
	return (result);
}
