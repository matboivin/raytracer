/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_coord.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:32:12 by mboivin           #+#    #+#             */
/*   Updated: 2020/09/03 15:45:41 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	scale = tan(degrees_to_radians(fov * 0.5));
	pixel_x = (
		2 * (x + 0.5) / (double)res.size_x - 1) * aspect_ratio * scale;
	pixel_y = (
		1 - 2 * (y + 0.5) / (double)res.size_y) * scale;
	result = create_vec3(pixel_x, pixel_y, 1);
	return (result);
}
