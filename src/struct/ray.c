/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 22:54:01 by mboivin           #+#    #+#             */
/*   Updated: 2020/07/27 20:47:24 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Ray
**
** create_ray() :  Constructor
*/

t_ray		create_ray(t_vec3 p_origin, t_vec3 p_dir, double p_t)
{
	t_ray	result;

	result.origin = p_origin;
	result.dir = p_dir;
	result.t = p_t;
	return (result);
}
