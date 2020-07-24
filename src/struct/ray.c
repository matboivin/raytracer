/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 22:54:01 by mboivin           #+#    #+#             */
/*   Updated: 2020/07/24 17:09:34 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Ray
**
** create_ray() :  Constructor
*/

t_ray		create_ray(t_coord3 p_origin, t_coord3 p_dir)
{
	t_ray	result;

	result.origin = p_origin;
	result.dir = p_dir;
	return (result);
}