/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 23:36:36 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/04 23:50:38 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	degrees_to_radians(double deg_angle)
{
	return ((deg_angle * M_PI) / 180.0);
}

double	radians_to_degrees(double rad_angle)
{
	return ((rad_angle * 180.0) / M_PI);
}
