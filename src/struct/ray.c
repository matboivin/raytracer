/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 00:48:03 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/29 21:45:34 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray		create_ray(t_vec3 p_origin, t_vec3 p_dir, double p_tnearest)
{
	t_ray	result;

	result.origin = p_origin;
	result.dir = p_dir;
	result.t_nearest = p_tnearest;
	result.vcolor = create_vec3(0.0, 0.0, 0.0);
	result.hit_p = create_vec3(0.0, 0.0, 0.0);
	result.normal = create_vec3(0.0, 0.0, 0.0);
	return (result);
}
