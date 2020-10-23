/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_coord.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:32:12 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/24 01:20:10 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "minirt.h"

/*
** This function converts pixel to World coordinates
*/

t_vec3		get_pixel_coord(double fov, t_res res, int x, int y)
{
	t_vec3	result;
	double	scale;
	double	pixel_x;
	double	pixel_y;
	double	aspect_ratio;

	aspect_ratio = (double)res.size_x / (double)res.size_y;
	scale = tan(degrees_to_radians(fov * HALF_DIV));
	pixel_x = (
		2.0 * (x + HALF_PIXEL) / (double)res.size_x - UNIT_VALUE)
		* aspect_ratio * scale;
	pixel_y = (
		UNIT_VALUE - 2.0 * (y + HALF_PIXEL) / (double)res.size_y) * scale;
	result = create_vec3(pixel_x, pixel_y, UNIT_VALUE);
	return (result);
}
