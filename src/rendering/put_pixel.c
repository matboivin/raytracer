/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 16:43:30 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/23 20:21:05 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function puts pixel in the MLX image data using a given color
**
** image data (image pixels) is a char pointer
**
** To get the index of a pixel in the image pixels:
** (x position + width * y position) * 4
** 1 pixel = 4 char so we multiply 4 times
*/

static t_uchar	convert_color(double value)
{
	return (fmin(255.0, fmax(0.0, value)));
}

void			put_pixel_to_image(t_img *img, t_color color, int x, int y)
{
	int			i;

	if ((ft_n_range(x, 0, img->size_x) == false)
		|| (ft_n_range(y, 0, img->size_y) == false))
		return ;
	i = (x + img->size_x * y) * 4;
	img->pixels[i + RED_COMP] = convert_color(color.r);
	img->pixels[i + GREEN_COMP] = convert_color(color.g);
	img->pixels[i + BLUE_COMP] = convert_color(color.b);
}
