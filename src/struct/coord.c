/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 21:38:29 by mboivin           #+#    #+#             */
/*   Updated: 2020/07/24 17:04:42 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** 3D coordinates
**
** create_coord3() :  Constructor
*/

t_coord3		create_coord3(double p_x, double p_y, double p_z)
{
	t_coord3	result;

	result.x = p_x;
	result.y = p_y;
	result.z = p_z;
	return (result);
}
