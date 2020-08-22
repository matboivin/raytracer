/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sphere_normal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 21:56:30 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/23 01:19:31 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function computes sphere normal at a point
*/

t_vec3		get_sphere_normal(t_vec3 hit_p, t_vec3 center)
{
	t_vec3	result;

	result = sub_vec3(hit_p, center);
	result = normalize_vec3(result);
	return (result);
}
