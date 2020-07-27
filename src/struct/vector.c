/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 21:38:29 by mboivin           #+#    #+#             */
/*   Updated: 2020/07/27 20:41:35 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** 3D Vector
**
** create_vec3() :  Constructor
*/

t_vec3		create_vec3(double p_x, double p_y, double p_z)
{
	t_vec3	result;

	result.x = p_x;
	result.y = p_y;
	result.z = p_z;
	return (result);
}
