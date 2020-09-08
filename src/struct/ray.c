/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 00:48:03 by mboivin           #+#    #+#             */
/*   Updated: 2020/09/09 00:20:26 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray		create_ray(t_vec3 p_origin, t_vec3 p_dir, double p_tnear)
{
	t_ray	result;

	result.origin = p_origin;
	result.dir = p_dir;
	result.t_nearest = p_tnear;
	result.vcolor = create_vec3(DEFAULT_VALUE, DEFAULT_VALUE, DEFAULT_VALUE);
	result.hit_p = create_vec3(DEFAULT_VALUE, DEFAULT_VALUE, DEFAULT_VALUE);
	result.normal = create_vec3(DEFAULT_VALUE, DEFAULT_VALUE, DEFAULT_VALUE);
	return (result);
}
